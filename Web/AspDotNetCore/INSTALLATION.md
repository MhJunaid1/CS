Official Documentation Link (https://learn.microsoft.com/en-us/dotnet/core/install/windows)
In the context of installing .NET on Windows, there are two important components: the **.NET SDK** and the **.NET Runtime**. Here's a more detailed explanation of both and how to install them.

### Key Components of .NET:

1. **.NET SDK (Software Development Kit)**:
   - The SDK is what you need to **build and develop** .NET applications.
   - It includes:
     - The **.NET Runtime**.
     - **Command-line tools** for building and running applications (`dotnet` command).
     - Libraries, compilers, and other tools necessary for development.
   - The SDK is required for both **building** and **running** applications on your development machine.
   
2. **.NET Runtime**:
   - The runtime is required to **run .NET applications** but doesn't include development tools.
   - It includes the **CLR (Common Language Runtime)** and base libraries necessary for executing compiled .NET applications.
   - You would typically install the runtime if you're only running applications, not developing them.

### Different Installers for .NET

When installing .NET, you may come across these options:

1. **.NET SDK Installer**:
   - Use this if you're developing .NET applications.
   - It includes both the SDK and the runtime.

2. **.NET Runtime Installer**:
   - Use this if you only need to run .NET applications, not develop them.
   - It can be installed separately for applications that need to run on servers or client machines.

3. **ASP.NET Core Runtime**:
   - This is a specialized runtime that includes the .NET runtime plus libraries and components for running **ASP.NET Core** applications.
   - It’s commonly used for hosting web applications on servers.

### Ways to Install the .NET SDK and Runtime on Windows

#### 1. **Installing the .NET SDK via Official Installer**
   - Go to the [.NET download page](https://dotnet.microsoft.com/download).
   - Select the **.NET SDK** version you need (e.g., .NET 7, .NET 6 LTS).
   - Download the installer for **Windows** and run it.
   - The SDK installer also installs the runtime.

   **Command after installation:**
   ```bash
   dotnet --version
   ```

#### 2. **Installing Only the .NET Runtime**
   - If you only need the runtime (e.g., for servers):
     - Go to the [.NET Runtime download page](https://dotnet.microsoft.com/download/dotnet) and select **.NET Runtime**.
     - Download and install the runtime for **Windows**.
   
   **Command after installation to check runtime versions:**
   ```bash
   dotnet --list-runtimes
   ```

#### 3. **Installing via Package Manager (`winget`)**

You can install both the SDK and runtime using Windows Package Manager.

- **Install the SDK**:
  ```bash
  winget install Microsoft.DotNet.SDK.7
  ```
  
- **Install the Runtime**:
  ```bash
  winget install Microsoft.DotNet.Runtime.7
  ```

You can replace `7` with the desired version (e.g., `6` for .NET 6 LTS).

#### 4. **Installing ASP.NET Core Runtime**
   If you're running web applications that use **ASP.NET Core**, you can install the specialized ASP.NET Core runtime.

   **Steps:**
   - Go to the [ASP.NET Core Runtime download page](https://dotnet.microsoft.com/download/dotnet).
   - Download the **ASP.NET Core Runtime** installer for the desired version.
   - Run the installer.

### How to Check Installed Versions

After installing .NET, you can check which SDKs and runtimes are installed on your machine using the following commands:

1. **Check Installed SDKs**:
   ```bash
   dotnet --list-sdks
   ```

2. **Check Installed Runtimes**:
   ```bash
   dotnet --list-runtimes
   ```

### Difference Between SDK and Runtime Installations:
- **SDK**: Includes everything you need to build and run .NET applications (including the runtime).
- **Runtime**: Only needed to run already built .NET applications.

If you're developing, always install the **SDK**. If you're just running applications, the **runtime** is enough.