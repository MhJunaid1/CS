In Angular, **Reactive Forms** do not use traditional two-way data binding (i.e., `[(ngModel)]`) as in template-driven forms. Instead, they rely on a **uni-directional data flow** between the component class and the form model. Here’s how data flows in reactive forms:

1. **Explicit Binding from Component to View**:
   - You define the form model (using `FormControl`, `FormGroup`, etc.) in the component, and bind it to the view using the `[formGroup]` and `formControlName` directives. 
   - When a value is updated in the component class, that update will reflect in the view because the form model is bound to the form controls.

2. **Observing Value Changes**:
   - To capture changes made in the form controls and reflect them in the component, you can use observables like `.valueChanges` on form controls. This allows you to observe and react to changes made by the user.
   - If you need to handle changes made to a control directly in the component class, you use methods like `setValue` or `patchValue`.

### Example of Value Changes in Reactive Forms

Here’s an example of setting up and listening to changes in a reactive form:

```typescript
import { Component } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';

@Component({
  selector: 'app-example',
  template: `
    <form [formGroup]="form">
      <input formControlName="name" placeholder="Enter name">
    </form>
  `
})
export class ExampleComponent {
  form: FormGroup;

  constructor(private fb: FormBuilder) {
    this.form = this.fb.group({
      name: ['', Validators.required]
    });

    // Listening to value changes in the form control
    this.form.get('name')?.valueChanges.subscribe(value => {
      console.log('Name changed to:', value);
      // Perform further actions based on new value
    });
  }

  // Setting value programmatically
  updateName(newName: string) {
    this.form.get('name')?.setValue(newName);
  }
}
```

### Summary
- **Reactive Forms** don’t use traditional two-way data binding (`[(ngModel)]`).
- Instead, they rely on **uni-directional data flow** and explicit control.
- Updates to the form control value can be observed via `.valueChanges`, which can be subscribed to in the component.
- Updates from the component to the view are done through methods like `setValue` and `patchValue`.