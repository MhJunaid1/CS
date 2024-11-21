In Angular, **data binding** is a mechanism that allows communication between the component (TypeScript code) and the view (HTML template). It ensures that the view reflects the state of the component and vice versa. Angular provides four types of data binding:

---

### **1. Interpolation**
- **Definition**: Displays dynamic data from the component in the HTML template.
- **Syntax**: Uses double curly braces `{{ }}`.
- **Direction**: One-way binding (component → view).

**Example**:
```typescript
// Component
export class AppComponent {
  title = 'Angular Data Binding';
}

// Template
<h1>{{ title }}</h1> <!-- Output: Angular Data Binding -->
```

- You can also use expressions inside interpolation:
  ```html
  <p>{{ 10 + 5 }}</p> <!-- Output: 15 -->
  ```

---

### **2. Property Binding**
- **Definition**: Binds a component's property to an HTML element’s property.
- **Syntax**: Uses square brackets `[ ]`.
- **Direction**: One-way binding (component → view).

**Example**:
```typescript
// Component
export class AppComponent {
  imageUrl = 'https://example.com/image.png';
}

// Template
<img [src]="imageUrl" alt="Example Image">
```

**When to Use**:
- Use property binding to dynamically set values like attributes, styles, or class properties.

---

### **3. Event Binding**
- **Definition**: Binds an event in the view to a method in the component.
- **Syntax**: Uses parentheses `( )`.
- **Direction**: One-way binding (view → component).

**Example**:
```typescript
// Component
export class AppComponent {
  onButtonClick() {
    console.log('Button clicked!');
  }
}

// Template
<button (click)="onButtonClick()">Click Me</button>
```

**When to Use**:
- Use event binding to handle user interactions, such as clicks, keypresses, or mouse movements.

---

### **4. Two-Way Binding**
- **Definition**: Combines property binding and event binding to create a synchronized connection between the component and the view.
- **Syntax**: Uses `[()]` (banana in a box).
- **Direction**: Two-way binding (component ↔ view).

**Example**:
```typescript
// Component
export class AppComponent {
  username = '';
}

// Template
<input [(ngModel)]="username" placeholder="Enter your name">
<p>Your name is: {{ username }}</p>
```

**When to Use**:
- Use two-way binding for form inputs or other controls where you need the view to update the component and vice versa.

**Note**: For two-way binding to work, the `FormsModule` must be imported into your Angular module.

---

### **Summary of Differences**

| **Type**             | **Syntax**     | **Direction**        | **Purpose**                     |
|-----------------------|----------------|-----------------------|----------------------------------|
| **Interpolation**     | `{{ expression }}` | Component → View    | Display dynamic data in templates. |
| **Property Binding**  | `[property]="value"` | Component → View | Bind component properties to element properties. |
| **Event Binding**     | `(event)="handler()"` | View → Component  | Handle user interactions.       |
| **Two-Way Binding**   | `[(ngModel)]="value"` | Component ↔ View  | Synchronize input fields with component properties. |

Each type of data binding serves a specific purpose and can be combined to create dynamic and interactive web applications in Angular.