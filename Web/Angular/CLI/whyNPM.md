Great question — and it touches on both **historical context** and **ecosystem compatibility**. Here's the full story:

---

### ✅ **Why Node.js Bundles `npm` by Default**

1. **npm was created by Node.js community itself**:

   * **npm** (Node Package Manager) was the **first and official** package manager for Node.js, introduced in 2010.
   * It was tightly coupled with the growth of Node.js, so it became the default very early on.

2. **npm is maintained by the Node.js Foundation (via OpenJS)**:

   * It’s developed and supported officially — so bundling it ensures **a consistent toolchain** for all Node.js users.

3. **Bundling ensures out-of-the-box usability**:

   * When someone installs Node.js, they **immediately get access to packages** and scripts via `npm`, without additional setup.
   * It's all about **ease of adoption and accessibility**.

---

### ❓ But Isn’t `pnpm` or `yarn` Better?

Yes — in certain ways:

| Tool     | Strengths                                                             |
| -------- | --------------------------------------------------------------------- |
| **npm**  | Standard, mature, built-in, supports workspaces, widely compatible    |
| **yarn** | Fast, deterministic (lock files), better offline support, plug'n'play |
| **pnpm** | **Best performance**, disk efficiency, strict dependency resolution   |

> But they are still **third-party alternatives**, and not official tools.

---

### 🤔 Why Not Switch to `pnpm` or `yarn` by Default?

Because:

* **npm is already good enough** for most use cases
* Switching would break many tools/scripts that assume `npm`
* Node.js wants to stay neutral and **not favor third-party tools**
* Advanced users can always choose to install `yarn` or `pnpm`

---

### 🔧 You Can Still Use Others Easily:

```bash
npm install -g pnpm
npm install -g yarn
```

And then:

```bash
pnpm install
yarn install
```

---

### TL;DR:

> **npm is bundled with Node.js because it’s the official, original package manager**. While `pnpm` and `yarn` offer improvements, Node.js sticks with `npm` for compatibility, simplicity, and stability. But you're always free to switch based on your needs.

Let me know if you want help switching to `pnpm` in an existing project — it's quite easy!
