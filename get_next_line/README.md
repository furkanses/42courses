# get_next_line

Bu proje, bir dosya tanımlayıcısından (file descriptor) satır satır veri okumayı sağlayan `get_next_line` fonksiyonunun yazılmasını amaçlamaktadır. Proje sayesinde hem statik değişken kullanımını hem de bellek yönetimini daha iyi öğrenmek mümkün olacaktır.

## 📁 İçerik

Proje kapsamında aşağıdaki dosyalar yazılmıştır:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

## 🧠 Fonksiyon Prototipi

```c
char *get_next_line(int fd);
```

- `fd`: Okunacak dosyanın file descriptor’ı.
- Dönüş değeri: Başarıyla okunan bir satır döner. EOF veya hata durumunda `NULL` döner.

## 📌 Özellikler

- Her çağrıda bir satır okunur. Satır sonu karakteri (`\n`) varsa satıra dahil edilir.
- Satır okunurken mümkün olduğunca az veri okunur.
- Hem dosyalardan hem de standart girdiden (`stdin`) doğru şekilde okuma yapar.
- `BUFFER_SIZE` tanımı kullanılarak farklı buffer boyutları ile çalışabilir.
- Kendi içinde static değişken kullanarak bir önceki çağrının durumunu korur.

## 🚫 Kısıtlamalar

- `lseek()` fonksiyonunun kullanımı yasaktır.
- Global değişken kullanımı yasaktır.
- `libft` kütüphanesi bu projede kullanılamaz.

## ⚙️ Derleme

Kodunuzu aşağıdaki şekilde derleyebilirsiniz (örnek buffer size: 42):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

## 📄 Notlar

- Bu README dosyası yalnızca **zorunlu kısım** için hazırlanmıştır. Bonus özellikler dahil edilmemiştir.
- Kod `Norminette` standartlarına uygun şekilde yazılmıştır.
- Tüm heap belleği sızıntısız şekilde yönetilmektedir.
