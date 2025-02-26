

Everything about thread safety and singleton patterns in detail.

1. **Basic Singleton Without Thread Safety**
```csharp
public class UnsafeApiClient
{
    private static UnsafeApiClient _instance;
    
    private UnsafeApiClient() { }  // Private constructor

    public static UnsafeApiClient Instance
    {
        get 
        {
            if (_instance == null)
            {
                _instance = new UnsafeApiClient();
            }
            return _instance;
        }
    }
}
```
Problem: Multiple threads could create multiple instances.

2. **Simple Thread-Safe Singleton (But Inefficient)**
```csharp
public class SimpleThreadSafeApiClient
{
    private static SimpleThreadSafeApiClient _instance;
    private static readonly object _lock = new object();
    
    private SimpleThreadSafeApiClient() { }

    public static SimpleThreadSafeApiClient Instance
    {
        get 
        {
            lock (_lock)  // Every access requires lock
            {
                if (_instance == null)
                {
                    _instance = new SimpleThreadSafeApiClient();
                }
                return _instance;
            }
        }
    }
}
```
Problem: Takes a performance hit because it locks on every access.

3. **Double-Check Locking Pattern**
```csharp
public class DoubleCheckApiClient
{
    private static DoubleCheckApiClient _instance;
    private static readonly object _lock = new object();
    private readonly HttpClient _httpClient;

    private DoubleCheckApiClient() 
    {
        _httpClient = new HttpClient();
    }

    public static DoubleCheckApiClient Instance
    {
        get 
        {
            // First check (without lock)
            if (_instance == null)
            {
                lock (_lock)
                {
                    // Second check (with lock)
                    if (_instance == null)
                    {
                        _instance = new DoubleCheckApiClient();
                    }
                }
            }
            return _instance;
        }
    }
}
```

Let's see what happens with multiple threads:
```plaintext
Time    Thread1                     Thread2
----    -------                     -------
1       Checks if instance null
2                                   Checks if instance null
3       Enters lock
4                                   Waits for lock
5       Creates instance
6       Exits lock
7                                   Gets lock
8                                   Sees instance exists
9                                   Returns existing instance
```

4. **Modern Approach using Lazy<T>**
```csharp
public class ModernApiClient
{
    // LazyThreadSafetyMode.ExecutionAndPublication ensures thread safety
    private static readonly Lazy<ModernApiClient> _lazyInstance = 
        new Lazy<ModernApiClient>(() => new ModernApiClient(), 
            LazyThreadSafetyMode.ExecutionAndPublication);

    private readonly HttpClient _httpClient;

    private ModernApiClient() 
    {
        _httpClient = new HttpClient();
    }

    public static ModernApiClient Instance => _lazyInstance.Value;

    // Example method
    public async Task<string> GetDataAsync(string url)
    {
        return await _httpClient.GetStringAsync(url);
    }
}
```

5. **Usage Examples**
```csharp
// Example 1: Basic usage
public class ExampleService
{
    public async Task DoSomething()
    {
        var client = ModernApiClient.Instance;
        var result = await client.GetDataAsync("https://api.example.com/data");
    }
}

// Example 2: Multiple threads accessing
public class MultiThreadExample
{
    public async Task RunMultipleRequests()
    {
        // These will all use the same instance
        var tasks = new List<Task>();
        for (int i = 0; i < 10; i++)
        {
            tasks.Add(Task.Run(async () => 
            {
                var client = ModernApiClient.Instance;
                await client.GetDataAsync($"https://api.example.com/data/{i}");
            }));
        }
        await Task.WhenAll(tasks);
    }
}
```

6. **Complete Modern Implementation**
```csharp
public class ApiClient
{
    private static readonly Lazy<ApiClient> _lazyInstance = 
        new Lazy<ApiClient>(() => new ApiClient());
    
    private readonly HttpClient _httpClient;
    private readonly string _baseUrl;
    private readonly JsonSerializerOptions _jsonOptions;

    private ApiClient()
    {
        _httpClient = new HttpClient();
        _baseUrl = "http://10.0.2.2:5187";
        _jsonOptions = new JsonSerializerOptions
        {
            PropertyNameCaseInsensitive = true,
            WriteIndented = true
        };
    }

    public static ApiClient Instance => _lazyInstance.Value;

    public async Task<ApiResponse<TResponse>> GetAsync<TResponse>(string endpoint, 
        object queryParams = null)
    {
        try
        {
            var url = BuildUrl(endpoint, queryParams);
            var response = await _httpClient.GetAsync(url);
            return await HandleResponse<TResponse>(response);
        }
        catch (Exception ex)
        {
            throw new Exception($"GetAsync failed: {ex.Message}", ex);
        }
    }

    private async Task<ApiResponse<T>> HandleResponse<T>(HttpResponseMessage response)
    {
        var content = await response.Content.ReadAsStringAsync();
        
        try
        {
            return JsonSerializer.Deserialize<ApiResponse<T>>(content, _jsonOptions)
                ?? throw new Exception("Deserialization returned null");
        }
        catch (JsonException)
        {
            // Handle direct response
            var directResponse = JsonSerializer.Deserialize<T>(content, _jsonOptions);
            return new ApiResponse<T>
            {
                Data = directResponse,
                Success = response.IsSuccessStatusCode,
                Message = response.ReasonPhrase
            };
        }
    }

    // Other methods...
}
```

7. **Best Practices**
- Always make the constructor private
- Use readonly fields where possible
- Consider implementing IDisposable if you need cleanup
- Use async/await consistently
- Handle exceptions appropriately
- Consider adding timeout and retry policies
- Use cancellation tokens for long-running operations

8. **Example Usage in Real Code**
```csharp
public class UserService
{
    public async Task<User> GetUserAsync(int userId)
    {
        try
        {
            var client = ApiClient.Instance;
            var response = await client.GetAsync<User>($"api/users/{userId}");
            
            if (!response.Success)
            {
                throw new Exception($"Failed to get user: {response.Message}");
            }
            
            return response.Data;
        }
        catch (Exception ex)
        {
            // Log error
            throw;
        }
    }
}
```

This implementation ensures:
- Thread safety
- Efficient resource usage
- Proper error handling
- Clean and maintainable code
- Consistent behavior across the application
- Proper memory management
- Easy testing and maintenance
