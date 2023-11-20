## Conventional Commits

This repository uses a stripped down version of [_conventional commits_](https://www.conventionalcommits.org/en/v1.0.0/). [This article](https://cbea.ms/git-commit) gives advice on how to do helpful commits.

```
<type>: subject (50 characters total)

[optional body] (Multiline, multi-paragraph that wraps at 72 characters.
```

### Commit types

| Type       | Meaning                                            |
| ---------- | -------------------------------------------------- |
| `feat`     | Adds a feature that satisfies a requirement.       |
| `fix`      | Fixes a bug in the code.                           |
| `docs`     | A documentation only change.                       |
| `style`    | A minor visual change.                             |
| `refactor` | A structural change only (not a feature or fix).   |
| `test`     | Adds or corrects a test.                           |
| `build`    | A change to the build system.                      |
| `ci`       | A change to continuous integration.                |
| `chore`    | Other changes that don’t modify src or test files. |
| `revert`   | Reverts a previous commit.                         |

### Commit examples

```
test: return NULL when malloc fails

This is a test for requirement #002: it checks whether
`_strdup` returns NULL when memory allocation fails.

To run the test:
       make test_that_null_is_returned_when_malloc_fails

The test uses 'malloc_fail_driver' as a prerequisite. It ensures
failure by overriding the call to malloc with a stub that always
returns NULL.
```

```
feat: pass return NULL when malloc fails

Adds a guard that checks whether malloc has returned NULL.
If NULL is returned, stops processing and returns NULL to the
caller.

Fulfils requirement #002.
```
