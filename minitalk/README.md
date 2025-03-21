# Minitalk

Bu proje, UNIX sinyalleri kullanarak client ve server arasında basit bir metin iletişimi gerçekleştirmeyi amaçlar. `kill()` fonksiyonu ile sinyal gönderme ve `sigaction()` gibi sinyal yakalama yöntemlerini kullanarak, düşük seviyeli bir iletişim protokolü oluşturulmuştur.

## 📁 İçerik

Projede aşağıdaki iki program yer alır:

- `server`: Client’tan gelen mesajları alır ve yazdırır.
- `client`: Belirtilen PID’ye sahip server’a string mesaj gönderir.

## ⚙️ Derleme

Projeyi derlemek için Makefile mevcuttur:

```bash
make
```

Temizlik işlemleri için:

```bash
make clean     # Nesne dosyalarını siler
make fclean    # Nesne dosyaları + binary dosyaları siler
make re        # Temizler ve yeniden derler
make bonus     # Bonus versiyonu derler
```

## 📌 Zorunlu Özellikler

- Server başlatıldığında kendi PID'sini ekrana yazdırır.
- Client aşağıdaki parametreleri alır:
  - Server PID’si
  - Gönderilecek mesaj
- Client mesajı bit düzeyinde (`SIGUSR1` ve `SIGUSR2`) sinyaller ile gönderir.
- Server mesajı aldıktan sonra hemen yazdırır.
- Server art arda birden fazla client’tan mesaj alabilir.

## ⭐ Bonus Özellikler

- **Onay sinyali (ACK):** Server, her karakteri aldıktan sonra client’a sinyal göndererek mesajın ulaştığını onaylar.
- **Unicode desteği:** UTF-8 karakterler desteklenir. Bu sayede Türkçe karakterler veya emojiler gibi çok baytlı karakterler de gönderilebilir.

## 🧠 Kullanılan Fonksiyonlar

Yalnızca aşağıdaki sistem fonksiyonları ve standart kütüphane fonksiyonları kullanılmıştır:

- `write`, `malloc`, `free`, `kill`, `getpid`, `pause`, `usleep`, `exit`
- `signal`, `sigemptyset`, `sigaddset`, `sigaction`
- `ft_printf` (kendi yazılmış versiyonu)

## 🔐 Kısıtlamalar

- İletişim sadece `SIGUSR1` ve `SIGUSR2` sinyalleriyle yapılmalıdır.
- Global değişken sadece **bir adet** kullanılabilir (server ve client için birer tane).

## 🧪 Test ve Kullanım

Server'ı başlat:

```bash
./server
```

Çıktı örneği:
```
Server PID: 12345
```

Client ile mesaj gönder:

```bash
./client 12345 "Merhaba, 42!"
```

## 📄 Notlar

- Kod `Norminette` kurallarına uygundur.
- Bellek sızıntısı bulunmamaktadır (valgrind ile test edilmiştir).
- Bonus özellikler sadece zorunlu kısım mükemmel şekilde tamamlandığında değerlendirilir.
