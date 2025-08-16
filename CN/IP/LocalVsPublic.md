**Local IP Address and Public IP address**:

---

## **1️⃣ Local IP Address (shown by `ipconfig`)**

* **Scope:** Only exists inside your **local network** (home, office, etc.)
* **Purpose:** Allows devices in your local network (laptop, phone, printer) to talk to each other.
* **Format:** Often in private IP ranges:

  * `192.168.x.x`
  * `10.x.x.x`
  * `172.16.x.x` to `172.31.x.x`
* **Who assigns it:** Your **router** (via DHCP)
* **Visibility:**

  * Not visible to the internet.
  * Only devices connected to the same router can see it.

📌 **Example:**
If your `ipconfig` shows `192.168.1.101`, that’s just your **private address** given by your Wi-Fi router.

---

## **2️⃣ Public IP Address (shown by whatismyipaddress.com)**

* **Scope:** Visible to **the internet**.
* **Purpose:** Identifies your whole network to external websites and services.
* **Format:** Can be IPv4 (`203.0.113.25`) or IPv6 (`2607:f8b0:4005:805::200e`).
* **Who assigns it:** Your **Internet Service Provider (ISP)**.
* **Visibility:**

  * Any site you visit can see this IP.
  * Often shared by multiple devices in your home via **NAT** (Network Address Translation) on your router.

📌 **Example:**
If WhatIsMyIPAddress.com shows `203.0.113.25`, that’s the **single outward-facing address** your ISP gave to your router.

---

## 🖼 **How They Relate**

Think of your **local IP** as your apartment number inside a building,
and your **public IP** as the street address of the building.

* **Local IP** = “Apartment 2B” (only meaningful to people inside the building)
* **Public IP** = “123 Main Street” (used by the rest of the world to send things to your building)

Your router acts as the **doorman**, translating between public IP and local IP.

---
