### **What Are Pipes in Angular?**

Pipes in Angular are a way to transform data in your templates. They allow you to format data before displaying it to the user without modifying the underlying component data. Pipes are often used for tasks like formatting dates, currency, percentages, or filtering data in arrays.

---

### **Built-in Angular Pipes**
Angular provides several built-in pipes, such as:
- **DatePipe**: Formats dates.
  ```html
  {{ today | date: 'MM/dd/yyyy' }}
  ```
- **UpperCasePipe**: Converts text to uppercase.
  ```html
  {{ name | uppercase }}
  ```
- **CurrencyPipe**: Formats numbers as currency.
  ```html
  {{ amount | currency: 'USD' }}
  ```

You can chain multiple pipes:
```html
{{ 'hello world' | uppercase | slice:0:5 }}
```

---

### **Custom Pipes**

When Angular's built-in pipes don't meet your needs, you can create a custom pipe.

#### **Steps to Create a Custom Pipe**

1. **Generate a Pipe**
   Use the Angular CLI to generate a new pipe:
   ```bash
   ng generate pipe <pipe-name>
   ```
   Example:
   ```bash
   ng generate pipe custom
   ```

   This generates two files:
   - `custom.pipe.ts`
   - `custom.pipe.spec.ts`

2. **Define the Pipe Logic**
   Open the `custom.pipe.ts` file and implement your logic. A pipe class:
   - Implements the `PipeTransform` interface.
   - Includes a `transform` method where the data transformation occurs.

   Example: A pipe that capitalizes the first letter of a string:
   ```typescript
   import { Pipe, PipeTransform } from '@angular/core';

   @Pipe({
     name: 'capitalize'
   })
   export class CapitalizePipe implements PipeTransform {
     transform(value: string): string {
       if (!value) return '';
       return value.charAt(0).toUpperCase() + value.slice(1).toLowerCase();
     }
   }
   ```

3. **Register the Pipe**
   The pipe is automatically added to the `declarations` array in the `@NgModule` decorator of the module (e.g., `app.module.ts`).

4. **Use the Pipe in a Template**
   You can now use your custom pipe in a template like any other pipe:
   ```html
   {{ 'angular' | capitalize }} <!-- Output: Angular -->
   ```

---

### **Custom Pipe with Parameters**
You can pass arguments to your custom pipe. For example, a pipe that repeats a string a specified number of times:

```typescript
import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'repeat'
})
export class RepeatPipe implements PipeTransform {
  transform(value: string, times: number): string {
    if (!value || times <= 0) return '';
    return value.repeat(times);
  }
}
```

Usage in a template:
```html
{{ 'Angular' | repeat:3 }} <!-- Output: AngularAngularAngular -->
```

---

### **Summary**
- **Pipes**: Used to format and transform data in templates.
- **Built-in Pipes**: Include `date`, `uppercase`, `currency`, etc.
- **Custom Pipes**:
  1. Generate with CLI: `ng generate pipe`.
  2. Implement transformation logic in the `transform` method.
  3. Use in templates like `{{ value | customPipeName }}`.
- Pipes are reusable and keep your template logic clean.