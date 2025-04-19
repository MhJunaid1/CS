Here’s a clear **step-by-step guide** to deploy your **ASP.NET Core Web API to IIS (Internet Information Services)** on Windows.

---

## ✅ Prerequisites

1. ✅ You’ve **built an ASP.NET Core Web API**
2. ✅ You’ve **installed IIS** on your Windows machine
3. ✅ Installed **.NET Hosting Bundle** (includes .NET Runtime + IIS integration)

---

## 🧱 Step 1: Install .NET Hosting Bundle

**Required for ASP.NET Core to run under IIS.**

🔗 Download from here:  
👉 [https://dotnet.microsoft.com/en-us/download/dotnet](https://dotnet.microsoft.com/en-us/download/dotnet)

- Choose the version matching your app (.NET 6/7/8)
- Install **ASP.NET Core Runtime + Hosting Bundle**
- Restart your system **after install**

---

## ⚙️ Step 2: Enable IIS and Required Features

1. Open **Control Panel → Programs → Turn Windows Features On or Off**
2. Enable:
   - ✅ **Internet Information Services**
   - ✅ **.NET Extensibility**
   - ✅ **ASP.NET**
   - ✅ **Request Filtering**
   - ✅ **Windows Authentication** *(if needed)*

---

## 🛠️ Step 3: Publish Your Web API from Visual Studio

1. Right-click your project → **Publish**
2. Choose:
   - Target: **Folder**
   - Location: e.g., `C:\Publish\MyApi`
3. Click **Publish**
   - It generates the compiled site ready for IIS

---

## 🌐 Step 4: Configure IIS

1. Open **IIS Manager** (`inetmgr`)
2. Right-click **Sites** → **Add Website**
3. Fill in:
   - **Site Name**: `MyWebAPI`
   - **Physical Path**: Browse to your published folder (e.g., `C:\Publish\MyApi`)
   - **Port**: e.g., `8080` or `80`
4. Click OK to create

---

## 🧾 Step 5: Set Application Pool to No Managed Code

1. In IIS Manager → Click **Application Pools**
2. Find the app pool for your new site
3. Right-click → **Basic Settings**
4. Set:
   - **.NET CLR Version** = **No Managed Code**
   - **Managed pipeline mode** = **Integrated**
5. Restart the App Pool

---

## 🔥 Step 6: Allow Access Through Firewall (Optional)

If accessing from another machine:

1. Open **Windows Defender Firewall**
2. Add **Inbound Rule**:
   - Allow TCP traffic on the port you used (e.g., 8080)
   - Name it `WebAPI_Port_8080`

---

## 🚀 Step 7: Test It!

1. Open browser and hit:
   ```
   http://localhost:8080/swagger
   ```
   or
   ```
   http://localhost:8080/api/yourcontroller
   ```

2. You should see your Web API in action!

---

## 🎁 Bonus: Use a Domain or Public IP?

- Add a **DNS binding** or **public IP** (via port forwarding or DNS config)
- Bind it in IIS using **"Bindings…"**

---

### 💡 Tips

- Always **publish in Release mode**
- Log errors by enabling **stdoutLogEnabled** in `web.config`
- Use **Kestrel** behind IIS if you're using reverse proxy scenarios

---
