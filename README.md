# sgets

The attempted secure use of `gets()` POC.

NOTE: Uses 32bytes as the buffer.. Good Luck!

# Build and Install
```bash
git clone https://github.com/lillypad/sgets.git
cd sgets/
make
make install
```

# Usage
```bash
echo 'hello' | sgets
sgets
```

# Interface
```text
/-----------------------------------------------------------------------\
|                    sgets - gets() Secure Implementation               |
|-----------------------------------------------------------------------|
|                                Examples:                              |
|-----------------------------------------------------------------------|
| echo 'hello' | ./sgets                                                |
| ./sgets                                                               |
|-----------------------------------------------------------------------|
|                                 Author:                               |
|-----------------------------------------------------------------------|
| Lilly Chalupowski                                                     |
|-----------------------------------------------------------------------|
|                         Press ENTER to Continue                       |
\-----------------------------------------------------------------------/

buffer before:
  0000  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
  0010  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
Good Luck! ┌∩┐(◣_◢)┌∩┐: Hello World!
buffer after:
  0000  48 65 6c 6c 6f 20 57 6f 72 6c 64 21 00 00 00 00  Hello World!....
  0010  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
Output: Hello World!
```

# How Does it Work
- Works on the premise that `gets()` uses `stdin` and terminates on `\n`.

# References
- [`ungetc`](https://linux.die.net/man/3/ungetc)
- [`fgetc`](https://linux.die.net/man/3/fgetc)
- [`dlopen`](https://linux.die.net/man/3/dlopen)
- [`dlsym`](https://linux.die.net/man/3/dlsym)
- [`gets`](http://man7.org/linux/man-pages/man3/gets.3.html)
