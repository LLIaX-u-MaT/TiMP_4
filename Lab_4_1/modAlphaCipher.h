#pragma once

#include <codecvt>
#include <cwctype>
#include <iostream>
#include <locale>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
/**
 * @file modAlphaCipher.h
 * @author Мочалов Ю.А.
 * @version 1.0
 * @date 09.12.2024
 * @brief Заголовочный файл для класса modAlphaCipher.
 *
 * Данный файл содержит определение класса modAlphaCipher, который реализует
 * методы шифрования и расшифрования текста с использованием заданного ключа.
 */

/**
 * @class modAlphaCipher
 * @brief Класс для шифрования и расшифрования текста с использованием модифицированного алфавитного шифра.
 *
 * Данный класс реализует шифрование и расшифрование текста на основе заданного ключа,
 * используя ассоциативный массив для сопоставления символов алфавита с их номерами.
 */
class modAlphaCipher
{
private:
    std::wstring numAlpha; // Алфавит по порядку
    std::map<char, int> alphaNum; // Ассоциативный массив "номер по символу"
    std::vector<int> key; // Ключ для шифрования/расшифрования

    /**
     * @brief Преобразует строку в вектор целых чисел, представляющий номера символов.
     * @param s Строка для преобразования.
     * @return Вектор целых чисел.
     */
    std::vector<int> convert(const std::wstring& s);

    /**
     * @brief Преобразует вектор целых чисел обратно в строку.
     * @param v Вектор целых чисел для преобразования.
     * @return Строка.
     */
    std::wstring convert(const std::vector<int>& v);

    /**
     * @brief Проверяет и возвращает валидный ключ для шифрования.
     * @param s Строка, представляющая ключ.
     * @return Валидный ключ в виде строки.
     * @throws cipher_error текст содержит недопустимые символы.
     */
    std::wstring getValidKey(const std::wstring& s);

    /**
     * @brief Проверяет и возвращает валидный открытый текст для шифрования.
     * @param s Открытый текст для проверки.
     * @return Валидный открытый текст.
     * @throws cipher_error текст содержит недопустимые символы.
     */
    std::wstring getValidOpenText(const std::wstring& s);

    /**
     * @brief Проверяет и возвращает валидный зашифрованный текст для расшифрования.
     * @param s Зашифрованный текст для проверки.
     * @return Валидный зашифрованный текст.
     * @throws cipher_error текст содержит недопустимые символы.
     */
    std::wstring getValidCipherText(const std::wstring& s);

public:
    /**
     * @brief Запрещает использование конструктора без параметров.
     */
    modAlphaCipher() = delete;

    /**
     * @brief Конструктор для установки ключа.
     * @param skey Строка, представляющая ключ шифрования.
     * @throws cipher_error текст содержит недопустимые символы.
     */
    modAlphaCipher(const std::wstring& skey);

    /**
     * @brief Зашифровывает открытый текст с использованием заданного ключа.
     * @param open_text Открытый текст для шифрования.
     * @return Зашифрованный текст.
     * @throws cipher_error текст содержит недопустимые символы.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /**
     * @brief Расшифровывает зашифрованный текст с использованием заданного ключа.
     * @param cipher_text Зашифрованный текст для расшифрования.
     * @return Открытый текст.
     * @throws cipher_error текст содержит недопустимые символы.
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};

/**
 * @class cipher_error
 * @brief Исключение, связанное с ошибками шифрования.
 *
 * Данный класс представляет собой пользовательское исключение, которое
 * наследуется от std::invalid_argument и используется для обработки ошибок,
 * возникающих при работе с классом modAlphaCipher.
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
