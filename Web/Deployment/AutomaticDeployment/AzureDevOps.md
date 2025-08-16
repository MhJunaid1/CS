
---

## 🔁 **What is a Pipeline in Azure DevOps?**

A **pipeline** is an automated workflow that **builds**, **tests**, and **deploys** your code whenever you make changes. Pipelines can be:

* **CI (Continuous Integration)** → Runs on every push/PR to build/test your app.
* **CD (Continuous Deployment/Delivery)** → Deploys your app to IIS, Azure, etc.

---

## 🧱 Types of Pipelines

| Type                 | Description                                                                       |
| -------------------- | --------------------------------------------------------------------------------- |
| **YAML Pipeline**    | Defined in code (`azure-pipelines.yml`), version-controlled, modern approach.     |
| **Classic Pipeline** | Drag-and-drop UI in Azure DevOps portal. Easier for beginners, but less portable. |

You can choose either. Most teams use **YAML pipelines** today for flexibility and Git-based versioning.

---

## 🧩 Basic Components of a Pipeline

| Component     | Description                                                                |
| ------------- | -------------------------------------------------------------------------- |
| **Trigger**   | Defines when the pipeline runs (e.g., on `push` to `main`).                |
| **Stages**    | Logical groups like Build, Test, Deploy.                                   |
| **Jobs**      | Unit of work running on an agent.                                          |
| **Steps**     | Tasks/scripts run in a job.                                                |
| **Tasks**     | Predefined actions like building a project, running tests, deploying, etc. |
| **Artifacts** | Outputs (e.g., .zip or binaries) from builds used in deployment.           |

---

## 🔧 Sample .NET Pipeline in YAML

```yaml
trigger:
  - main

pool:
  vmImage: 'windows-latest'

variables:
  buildConfiguration: 'Release'

steps:
- task: UseDotNet@2
  inputs:
    packageType: 'sdk'
    version: '8.x.x'
    installationPath: $(Agent.ToolsDirectory)/dotnet

- task: NuGetCommand@2
  inputs:
    restoreSolution: '**/*.sln'

- task: VSBuild@1
  inputs:
    solution: '**/*.sln'
    configuration: '$(buildConfiguration)'

- task: PublishBuildArtifacts@1
  inputs:
    pathToPublish: '$(Build.ArtifactStagingDirectory)'
    artifactName: 'drop'
```

This will:

1. Trigger on push to `main`
2. Install .NET SDK
3. Restore NuGet packages
4. Build your project
5. Publish build artifacts (used in deployment)

---

## 📦 Next Step

Now that you understand what a pipeline is, you have 2 main directions:

### ✅ Option 1: YAML Pipeline

* Create `azure-pipelines.yml` in root of repo
* Define the full pipeline as code (best practice)

### ✅ Option 2: Classic GUI Pipeline

* Use drag-and-drop interface in Azure DevOps
* Easier if you’re just starting out

---

