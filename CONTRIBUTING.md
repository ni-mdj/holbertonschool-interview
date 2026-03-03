# Contributing to Holberton Interview Preparation

Thank you for your interest in contributing to this project! This guide will help you understand how to contribute effectively.

---

## 📋 Code Standards

### Python
- **Style Guide:** PEP 8 (version 1.7.x)
- **Tools:** Use `pycodestyle` or `pylint` for linting
- **Docstrings:** Include comprehensive docstrings using Google style
- **Comments:** Clear comments for complex logic
- **Shebang:** First line must be `#!/usr/bin/python3`

### C
- **Style Guide:** Betty style guide
- **Tools:** `betty-style.pl` and `betty-doc.pl` for checking
- **Comments:** Proper documentation comments for functions
- **Memory:** Ensure no memory leaks; use valgrind to verify
- **Compilation:** Must compile with `-Wall -Wextra -Werror -pedantic`

---

## 🔄 Workflow

### 1. Create a Feature Branch
```bash
git checkout -b feature/your-feature-name
```

### 2. Make Your Changes
- Ensure code follows the appropriate style guide
- Add tests if applicable
- Update documentation if necessary

### 3. Test Your Changes
```bash
# For Python projects
python3 [project]/0-main.py

# For C projects
gcc -Wall -Wextra -Werror -pedantic *.c -o test
./test
```

### 4. Commit Your Changes
```bash
git commit -m "Brief description of changes"
```

Use clear, concise commit messages:
- Start with a verb (Add, Fix, Update, etc.)
- Be specific about what changed
- Keep it under 50 characters

### 5. Push and Create a Pull Request
```bash
git push origin feature/your-feature-name
```

---

## 📝 Commit Message Examples

**Good:**
- "Add edge case handling for empty input"
- "Fix memory leak in linked list insertion"
- "Update heap insertion documentation"
- "Improve algorithm complexity analysis"

**Poor:**
- "Fix bug"
- "Updated stuff"
- "Changes"
- "WIP"

---

## 📚 Documentation Guidelines

When contributing, ensure:

1. **README Updates**
   - Clear problem statement
   - Algorithm explanation
   - Time/space complexity
   - Example execution
   - Test cases

2. **Code Comments**
   - Explain complex logic
   - Document edge cases
   - Include before/after for algorithms

3. **Function Documentation**
   ```c
   /**
    * function_name - Brief description
    * @param1: Parameter description
    * @param2: Parameter description
    *
    * Description: Longer explanation if needed
    * Return: Description of return value
    */
   ```

   ```python
   def function_name(param1, param2):
       """Brief description.
       
       Longer explanation if needed.
       
       Args:
           param1: Description
           param2: Description
           
       Returns:
           Description of return value
       """
   ```

---

## 🧪 Testing Requirements

### Test Coverage
- All functions must have test cases
- Include edge cases
- Test boundary conditions
- Test error cases

### Python Tests
```bash
python3 -m pytest [file] -v  # If using pytest
python3 [file]               # Or run main directly
```

### C Tests
```bash
gcc -Wall -Wextra -Werror -pedantic [files] -o test
./test
```

---

## 🐛 Bug Reports

When reporting bugs, include:
- What you were trying to do
- What happened
- What you expected to happen
- Steps to reproduce
- Platform/environment information

---

## 💡 Suggestions for Improvements

- Better algorithms or optimizations
- Additional test cases
- Clearer explanations
- Performance improvements
- New approaches or solutions

---

## ✅ Checklist Before Submitting

- [ ] Code follows the style guide
- [ ] Compilation/execution works without errors
- [ ] Tests pass
- [ ] Comments and documentation are clear
- [ ] No unnecessary files are added
- [ ] Commit messages are descriptive
- [ ] README is updated if needed

---

## 🚀 Getting Started

1. Fork the repository
2. Clone your fork
3. Create a feature branch
4. Make changes following the guidelines
5. Test thoroughly
6. Submit a pull request with clear description

---

## 📞 Questions?

For questions or clarifications:
1. Check the README files in each project
2. Review existing code for patterns
3. Consult the QUICK_REFERENCE.md guide
4. Open an issue for discussion

---

## 📄 License

By contributing, you agree that your contributions will be licensed under the same license as the project.

---

Thank you for contributing! 🙏
