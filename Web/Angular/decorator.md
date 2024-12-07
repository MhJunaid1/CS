In Angular, a **decorator** is a special type of function that attaches metadata to a class, property, method, or parameter. Angular uses decorators to define and configure components, services, modules, and other building blocks of an Angular application.

### Key Points About Decorators in Angular:
1. **Metadata Providers**: Decorators provide metadata about a class or method to Angular's runtime, enabling the framework to process and use them appropriately.
2. **TypeScript Feature**: Angular decorators leverage TypeScript's decorator feature, denoted by the `@` symbol.

---

### Types of Angular Decorators:
1. **Class Decorators**:
   - Used to define and configure classes.
   - Examples:
     - `@Component`: Marks a class as an Angular component and provides its metadata.
     - `@NgModule`: Defines an Angular module.

2. **Property Decorators**:
   - Used to bind properties in a class.
   - Examples:
     - `@Input`: Allows data to flow into a component from a parent component.
     - `@Output`: Enables a component to emit events to its parent.

3. **Method Decorators**:
   - Used to define metadata for methods.
   - Example:
     - `@HostListener`: Binds a method to a DOM event listener.

4. **Parameter Decorators**:
   - Used to inject dependencies into a constructor.
   - Example:
     - `@Inject`: Provides a manual mechanism for dependency injection.

---

### Examples of Angular Decorators:

#### 1. `@Component` Decorator
Used to define an Angular component:
```typescript
import { Component } from '@angular/core';

@Component({
  selector: 'app-example',
  template: `<h1>Hello, Angular!</h1>`,
  styles: [`h1 { color: blue; }`]
})
export class ExampleComponent {}
```

#### 2. `@Input` Decorator
Used to pass data from a parent to a child component:
```typescript
import { Component, Input } from '@angular/core';

@Component({
  selector: 'app-child',
  template: `<p>{{ data }}</p>`
})
export class ChildComponent {
  @Input() data!: string;
}
```

#### 3. `@NgModule` Decorator
Defines an Angular module:
```typescript
import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { AppComponent } from './app.component';

@NgModule({
  declarations: [AppComponent],
  imports: [BrowserModule],
  bootstrap: [AppComponent]
})
export class AppModule {}
```

---

### Why Are Decorators Important in Angular?
1. **Declarative Syntax**: Simplifies application development by making configurations clear and intuitive.
2. **Dependency Injection**: Provides metadata for Angular's dependency injection system.
3. **Customization**: Allows developers to extend functionality and define application behavior declaratively.

---

Let me know if you’d like examples for specific use cases!