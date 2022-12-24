## Coding style for the C++ project

### Brackets
- Always open them *next to* the command.<br>*example:*
```c
void foo() {
   // code
}
``` 
- for one-line commands don't use brackets.<br>*example:*
```c
if (condition)
    // code
```
### Indentation
- Use **spaces**, NOT **tabs**, to make code appear the same in all editors. Standar size = 4 spaces.

### Pointers
- Always put "*" next to data type, NOT next to name. Conceptually, `int*` is a type.<br>*example:*
```c
int* foo(char* param)
{
    int* pointer = &var;
    // more code
}
```

### Names
- **Functions, variables, parameters:** `lowercase_with_underscores`
- **Types:** `CamelCase`
- **Constants:** `UPPERCASE`


### Comments
- One-line comments: `// comment`
- Multi-line commnets: `/* comment */`

