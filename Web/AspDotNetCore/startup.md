Commonly used .NET CLI commands, along with explanations for each:

### 1. **Creating a New .NET Project**
   - Command: `dotnet new console`
   - **Explanation**: This command creates a new console application in the current directory. You can replace `console` with another template, such as `web`, `classlib`, or `webapi` for different types of projects.

   Example:
   ```bash
   dotnet new console
   ```

---

### 2. **Restoring Dependencies**
   - Command: `dotnet restore`
   - **Explanation**: Restores the dependencies and tools needed to run the application. This command is used to download packages specified in the `*.csproj` or `*.fsproj` file.
   
   Example:
   ```bash
   dotnet restore
   ```

---

### 3. **Building the Project**
   - Command: `dotnet build`
   - **Explanation**: Compiles the project into an executable or a library. It restores dependencies first if necessary. The output is typically stored in the `bin/Debug` or `bin/Release` folder, depending on the configuration.

   Example:
   ```bash
   dotnet build
   ```

   You can also specify the configuration:
   ```bash
   dotnet build --configuration Release
   ```

---

### 4. **Running the Project**
   - Command: `dotnet run`
   - **Explanation**: Builds and runs the project. This is useful during development to test your application.

   Example:
   ```bash
   dotnet run
   ```

---

### 5. **Publishing for Production**
   - Command: `dotnet publish`
   - **Explanation**: Packages the application into a folder that can be deployed. It includes the compiled binaries, dependencies, and runtime configuration files. By default, it publishes in `bin/Release/netX.X/publish/` (X.X depends on your .NET version).

   Example for release configuration:
   ```bash
   dotnet publish --configuration Release
   ```

   You can also specify the target runtime:
   ```bash
   dotnet publish --configuration Release --runtime win-x64
   ```

---

### 6. **Cleaning the Project**
   - Command: `dotnet clean`
   - **Explanation**: Cleans the output of the previous build (removes files from the `bin` and `obj` directories). This is useful for starting fresh.

   Example:
   ```bash
   dotnet clean
   ```

---

### 7. **Running Tests**
   - Command: `dotnet test`
   - **Explanation**: Builds the project and runs any unit tests (if there are any test projects in the solution).

   Example:
   ```bash
   dotnet test
   ```

---

### 8. **Running the Application in Debug Mode**
   - Command: `dotnet run --configuration Debug`
   - **Explanation**: Runs the application in Debug mode, which includes additional debug information like symbols, making it easier to debug issues.

   Example:
   ```bash
   dotnet run --configuration Debug
   ```

---

### 9. **Viewing Installed .NET SDKs**
   - Command: `dotnet --list-sdks`
   - **Explanation**: Lists all the installed .NET SDK versions on your system.

   Example:
   ```bash
   dotnet --list-sdks
   ```

---

### 10. **Viewing Installed .NET Runtimes**
   - Command: `dotnet --list-runtimes`
   - **Explanation**: Lists all installed .NET runtimes on your system.

   Example:
   ```bash
   dotnet --list-runtimes
   ```

---

### Workflow Example:

1. Create a project:
   ```bash
   dotnet new console
   ```

2. Build the project:
   ```bash
   dotnet build
   ```

3. Run the project:
   ```bash
   dotnet run
   ```

4. Publish the project for production:
   ```bash
   dotnet publish --configuration Release
   ```

This sequence ensures you can easily develop, test, and deploy a .NET application!