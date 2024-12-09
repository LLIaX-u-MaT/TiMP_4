#pragma once

#include <cctype>
#include <cmath>
#include <iostream>
#include <locale>
#include <vector>
#include <codecvt>

/**
 * @file modCipherBeta.h
 * @author Мочалов Ю.А.
 * @version 1.0
 * @date 09.12.2024
 * @brief Заголовочный файл для класса Cipher.
 *
 * Данный файл содержит определение класса Cipher, который реализует методы
 * шифрования и расшифрования текста с использованием заданного ключа.
 */

/**
 * @class Cipher
 * @brief Класс для шифрования и расшифрования текста.
 *
 * Данный класс реализует методы шифрования и расшифрования текста
 * на основе числового ключа. Класс обеспечивает проверку корректности
 * ключа и текста перед выполнением операций шифрования и расшифрования.
 */
class Cipher
{
private:
    int key; ///< Ключ для шифрования/расшифрования.

public:
    /**
     * @brief Запрещает использование конструктора без параметров.
     */
    Cipher() = delete;

    /**
     * @brief Конструктор для установки ключа.
     * @param key_str Строка, представляющая ключ шифрования.
     * @throw cipher_error Если ключ некорректен.
     */
    Cipher(const std::wstring& key_str);

    /**
     * @brief Зашифровывает текст с использованием заданного ключа.
     * @param text Открытый текст для шифрования.
     * @return Зашифрованный текст.
     * @throw cipher_error Если текст некорректен.
     */
    wstring encrypt(const wstring& text);

    /**
     * @brief Расшифровывает зашифрованный текст с использованием заданного ключа.
     * @param text Зашифрованный текст для расшифрования.
     * @return Открытый текст.
     * @throw cipher_error Если текст некорректен.
     */
    wstring decrypt(const wstring& text);

    /**
     * @brief Проверяет и возвращает валидный ключ для шифрования.
     * @param key_str Строка, представляющая ключ.
     * @return Валидный ключ в виде целого числа.
     * @throw cipher_error Если ключ некорректен.
     */
    int getValidKey(const std::wstring& key_str);

    /**
     * @brief Проверяет и возвращает валидный открытый текст для шифрования.
     * @param s Открытый текст для проверки.
     * @return Валидный открытый текст.
     */
    std::wstring getValidOpenText(const std::wstring& s);

    /**
     * @brief Проверяет и возвращает валидный зашифрованный текст для расшифрования.
     * @param s Зашифрованный текст для проверки.
     * @return Валидный зашифрованный текст.
     */
    std::wstring getValidCipherText(const std::wstring& s);
};

/**
 * @class cipher_error
 * @brief Исключение, связанное с ошибками шифрования.
 *
 * Данный класс представляет собой пользовательское исключение, которое
 * наследуется от std::invalid_argument и используется для обработки ошибок,
 * возникающих при работе с классом Cipher.
 */
class cipher_error : public std::invalid_argument
{
public:
    /**
     * @brief Конструктор исключения с сообщением об ошибке.
     * @param what_arg Сообщение об ошибке в виде строки.
     */
    explicit cipher_error(const std::string& what_arg);

    /**
     * @brief Конструктор исключения с сообщением об ошибке.
     * @param what_arg Сообщение об ошибке в виде C-строки.
     */
    explicit cipher_error(const char* what_arg);
};
