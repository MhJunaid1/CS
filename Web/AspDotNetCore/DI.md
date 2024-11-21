### **Dependency Injection (DI) in ASP.NET Core**

**Dependency Injection (DI)** is a design pattern and technique in ASP.NET Core used to achieve **Inversion of Control (IoC)**. It enables the creation of loosely coupled, maintainable, and testable code by injecting dependencies into classes rather than hard-coding them.

---

### **Key Concepts of DI in ASP.NET Core**

1. **Dependency**:
   - Any service or class your application needs to perform its tasks.
   - For example, if a `Controller` needs a logging service, the logging service is a **dependency**.

2. **Injection**:
   - The process of providing a dependency to a class at runtime instead of instantiating it within the class.

3. **Inversion of Control (IoC)**:
   - A principle where the control of object creation and lifecycle is shifted from the class itself to a central container (IoC container).

---

### **Benefits of DI in ASP.NET Core**
- **Loosely Coupled Code**: Classes depend on abstractions rather than concrete implementations.
- **Testability**: Makes unit testing easier because mock dependencies can be injected.
- **Maintainability**: Centralized control of dependency lifetimes and configurations.
- **Flexibility**: Easy to replace implementations of services without changing the dependent code.

---

### **How DI Works in ASP.NET Core**

ASP.NET Core comes with a built-in **IoC container** that supports DI. The process involves:
1. **Registering Services**: Add services to the IoC container.
2. **Injecting Services**: Request services from the container in classes.

---

### **Steps for Dependency Injection**

#### **1. Registering Services**
Services are registered in the `Program.cs` file or `Startup.cs` (in earlier versions).

```csharp
var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddSingleton<ILoggingService, ConsoleLoggingService>();
builder.Services.AddScoped<IRepository, DatabaseRepository>();
builder.Services.AddTransient<IEmailService, EmailService>();

var app = builder.Build();
```

- **`AddSingleton`**: Creates a single instance of the service for the application’s lifetime.
- **`AddScoped`**: Creates one instance per HTTP request.
- **`AddTransient`**: Creates a new instance every time it is requested.

#### **2. Injecting Services**
You can inject services into constructors, methods, or properties.

##### **Constructor Injection** (Preferred method):
```csharp
public class HomeController : Controller
{
    private readonly ILoggingService _logger;

    public HomeController(ILoggingService logger)
    {
        _logger = logger;
    }

    public IActionResult Index()
    {
        _logger.Log("Accessed Home Index");
        return View();
    }
}
```

##### **Method Injection**:
```csharp
public IActionResult Index([FromServices] ILoggingService logger)
{
    logger.Log("Accessed Home Index");
    return View();
}
```

##### **Property Injection**:
```csharp
[Inject]
public ILoggingService Logger { get; set; }

public IActionResult Index()
{
    Logger.Log("Accessed Home Index");
    return View();
}
```

#### **3. Resolving Dependencies**
ASP.NET Core automatically resolves the dependencies from the IoC container. You don’t need to manually create instances.

---

### **Service Lifetime Options**

| Lifetime     | Description                                            | Use Case                                   |
|--------------|--------------------------------------------------------|-------------------------------------------|
| **Singleton** | One instance is shared across the entire application.  | For stateless services like configuration. |
| **Scoped**    | One instance per HTTP request.                         | For services tied to user requests, like repositories. |
| **Transient** | A new instance is created each time it's requested.    | Lightweight, stateless services.          |

---

### **Example: Dependency Injection in ASP.NET Core**

#### **Step 1: Create an Interface**
```csharp
public interface ILoggingService
{
    void Log(string message);
}
```

#### **Step 2: Create an Implementation**
```csharp
public class ConsoleLoggingService : ILoggingService
{
    public void Log(string message)
    {
        Console.WriteLine($"Log: {message}");
    }
}
```

#### **Step 3: Register the Service**
In `Program.cs`:
```csharp
builder.Services.AddSingleton<ILoggingService, ConsoleLoggingService>();
```

#### **Step 4: Inject the Service**
```csharp
public class HomeController : Controller
{
    private readonly ILoggingService _logger;

    public HomeController(ILoggingService logger)
    {
        _logger = logger;
    }

    public IActionResult Index()
    {
        _logger.Log("Accessed Home Index");
        return View();
    }
}
```

---

### **Advanced Features of DI in ASP.NET Core**

1. **Multiple Implementations of an Interface**
   You can register multiple implementations and resolve a specific one using named services or factories.

   ```csharp
   builder.Services.AddSingleton<ILoggingService, ConsoleLoggingService>();
   builder.Services.AddSingleton<ILoggingService, FileLoggingService>();
   ```

2. **Using Factories**
   Register services dynamically with custom logic:
   ```csharp
   builder.Services.AddSingleton<ILoggingService>(provider =>
   {
       return new ConsoleLoggingService();
   });
   ```

3. **Scoped Services in Middleware**
   Inject scoped services in custom middleware:
   ```csharp
   app.Use(async (context, next) =>
   {
       var logger = context.RequestServices.GetRequiredService<ILoggingService>();
       logger.Log("Middleware log");
       await next();
   });
   ```

4. **Options Pattern for Configuration**
   Use DI to inject strongly typed configuration settings:
   ```csharp
   builder.Services.Configure<AppSettings>(builder.Configuration.GetSection("AppSettings"));
   ```

---

### **Summary**
- **Dependency Injection (DI)** in ASP.NET Core simplifies dependency management by centralizing it in the IoC container.
- **Three Service Lifetimes**: Singleton, Scoped, Transient.
- **Injection Methods**: Constructor injection (preferred), method injection, and property injection.
- DI improves **maintainability**, **testability**, and **loose coupling**, making it a core feature of ASP.NET Core applications.