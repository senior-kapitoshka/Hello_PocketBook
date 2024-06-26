Простейшее приложение для устройства электронной книги PocketBook.
При запуске приложения на устройстве на экране появляется приветствие "Hello PocketBook World!".
Код приложения - частично измененный код-пример из гайда https://github.com/pocketbook-free/InkViewDoc.
Для сборки приложения нужно:
- клонировать репозиторий с SDK:
```
git clone https://github.com/pocketbook-free/SDK_481.git "$PBSDK"
cd "$PBSDK"
git checkout 5.12
```
- в файле CmakeLists.txt указать в настройках расположение SDK в вашей файловой системе:
```
set(TOOLCHAIN_PATH "/home/..some_path.../PBSDK")
```
- настроить Cmake:
```
cmake .
```
- для сборки приложения:
```
make
```
- чтобы запустить приложение, нам нужно перенести его на устройство (с помощью USB-кабеля) и поместить в папку applications/. Затем он появится в панели приложений, что позволит нам запустить его.

Протестировано на устройстве PocketBook 740 Pro
![photo_2024-06-21_13-02-13](https://github.com/senior-kapitoshka/Hello_PocketBook/assets/159151320/942003c3-a04f-4945-bb34-1ba2f418d945)
