/*Створіть програму, яка генерує випадкові паролі за заданими параметрами користувача.Користувач повинен мати можливість вказати
довжину паролю та типи символів, які мають використовуватися(наприклад, великі та малі літери, цифри, спеціальні символи).

Основні кроки :

Користувач вказує довжину паролю та типи символів через консоль.
Програма генерує випадковий пароль і виводить його.
Користувач може вказати, чи потрібно згенерувати ще один пароль.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int len, int up, int down, int digit, int specialchars)
{
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char special[] = "!@#$%^&*()-=_+[]{}|;':,.<>?/";

    char password[100];
    int passwordLength = 0;

    // Використовуйте великі літери, якщо користувач обрав цей тип символу
    if (up)
    {
        password[passwordLength++] = uppercase[rand() % (sizeof(uppercase) - 1)];
    }

    // Використовуйте малі літери, якщо користувач обрав цей тип символу
    if (down)
    {
        password[passwordLength++] = lowercase[rand() % (sizeof(lowercase) - 1)];
    }

    // Використовуйте цифри, якщо користувач обрав цей тип символу
    if (digit)
    {
        password[passwordLength++] = digits[rand() % (sizeof(digits) - 1)];
    }

    // Використовуйте унікальні символи, якщо користувач обрав цей тип символу
    if (specialchars)
    {
        password[passwordLength++] = special[rand() % (sizeof(special) - 1)];
    }

    for (int i = passwordLength; i < len; ++i)
    {
        int type = rand() % 4;

        switch (type)
        {
        case 0:
            password[i] = uppercase[rand() % (sizeof(uppercase) - 1)];
            break;
        case 1:
            password[i] = lowercase[rand() % (sizeof(lowercase) - 1)];
            break;
        case 2:
            password[i] = digits[rand() % (sizeof(digits) - 1)];
            break;
        case 3:
            password[i] = special[rand() % (sizeof(special) - 1)];
            break;
        }
    }
    password[len] = '\0';
    printf("Згенерований пароль: %s\n", password);
}

int main()
{
    srand(time(NULL));
    int len, up, down, digit, specialchars;
    char onemore;
    system("chcp 1251");

    do
    {
        printf("Введіть довжину пароля: \n");
        scanf_s("%d", &len);

        printf("Введіть чи потрібно використовувати велику літеру(1  - так; 0 - ні):\n ");
        scanf_s("%d", &up);

        printf("Введіть чи потрібно використовувати малу літеру(1  - так; 0 - ні):\n ");
        scanf_s("%d", &down);

        printf("Введіть чи потрібно використовувати цифри (1  - так; 0 - ні):\n ");
        scanf_s("%d", &digit);

        printf("Введіть чи потрібно використовувати унікальні символи (1  - так; 0 - ні):\n ");
        scanf_s("%d", &specialchars);

        // Викликайте функцію generatePassword
        generatePassword(len, up, down, digit, specialchars);

        printf("Згенерувати ще один пароль? (натисніть 'y' або 'Y')");
        scanf_s(" %c", &onemore);

    } while (onemore == 'Y' || onemore == 'y');

    return 0;
}
