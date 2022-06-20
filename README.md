# Encryption

This is demo of how we can acheive encryption using matrix and inverse matrix

## Screenshots

![App Screenshot](https://github.com/avi465/Encryption/blob/master/images/Screenshot.png)

## Working
<u>Step1:</u> First message is converted into numbers by any algorithm. Let's say according to its ascii value.<br>
for example: hello <-> [104 101 108 108 111]<br>

<u>Step2:</u> Then we multiply the matrix(key) with the message and get the cipher text.<br>

<u>Step3:</u> To decrypt we multiply the inverse matrix with the cipher text and get the original message.<br>

<u>Step4:</u> To get the original message we need to convert the numbers back to characters.<br>

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



