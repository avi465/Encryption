# Encryption

This is demo of how we can acheive encryption using matrix and inverse matrix

## Screenshots

![App Screenshot](https://github.com/avi465/Encryption/blob/master/images/Screenshot.png)

## Working
```Step1: First message is converted into numbers by any algorithm. Let's say according to its ascii value.for example: hello <-> [104 101 108 108 111]<br>```

```Step2: Then we multiply the matrix(key) with the message and get the cipher text.<br>```

```Step3: To decrypt we multiply the inverse matrix with the cipher text and get the original message.<br>```

```Step4: To get the original message we need to convert the numbers back to characters.<br>```

## Run Locally

Clone the project

```bash
  git clone https://github.com/avi465/Encryption.git
```

Go to the project directory

```bash
  cd my-project
```

Compile c file

```bash
  gcc Encryption.c
```

Run the program

```bash
  ./a.out
```



