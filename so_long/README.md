# so_long

Bu proje, 2D grafik kullanarak küçük bir oyun geliştirme alıştırmasıdır. `MiniLibX` grafik kütüphanesi kullanılarak, karakterin haritada dolaşıp tüm eşyaları topladıktan sonra çıkışa ulaşmasını hedefleyen bir oyun oluşturulur.

## 🎯 Amaç

Oyuncu, harita üzerindeki tüm **collectible** (toplanabilir nesneleri) topladıktan sonra çıkışa (`E`) ulaşarak oyunu tamamlamalıdır.

## 🧱 Oyun Kuralları

- Oyuncu karakteri `W`, `A`, `S`, `D` tuşlarıyla yukarı, sola, aşağı ve sağa hareket eder.
- Oyuncu duvarlara (`1`) çarpamaz.
- Her hareket, terminale yazdırılmalıdır: örn. `Hareket: 3`.
- Oyuncu, sadece **geçerli bir yol** varsa çıkışa ulaşabilir.
- ESC tuşuna basıldığında veya pencere kapatıldığında program düzgün şekilde sonlanmalıdır.

## 🗺️ Harita Kuralları

- Harita yalnızca şu karakterleri içerebilir:
  - `0` → Boşluk
  - `1` → Duvar
  - `C` → Collectible (toplanabilir eşya)
  - `E` → Çıkış
  - `P` → Oyuncunun başlangıç konumu
- Harita dikdörtgen olmalı ve tamamen duvarlarla çevrili olmalıdır.
- Haritada **en az bir `C`**, **bir `P`** ve **bir `E`** bulunmalıdır.
- Harita `.ber` uzantılı dosya olarak program parametresiyle verilmelidir.

## 🖼️ Grafiksel Gereklilikler

- Oyun penceresi açılmalı ve tüm elemanlar MiniLibX ile çizilmelidir.
- Görüntü gerçek zamanlı olmasa da pürüzsüz olmalı.
- Her grafik eleman bir sprite veya tile ile temsil edilmelidir.

## ⚙️ Derleme ve Kullanım

```bash
make
./so_long map.ber
```

### Makefile Kuralları

- `make`, `make clean`, `make fclean`, `make re` kurallarını içermelidir.
- `-Wall -Wextra -Werror` flagleriyle derlenmelidir.
- Gereksiz relink yapılmamalıdır.

## 🚫 Kısıtlamalar

- Tüm `malloc` kullanımları sonrasında uygun `free` işlemleri yapılmalıdır.
- Bellek sızıntısına izin verilmez.
- Hatalı harita dosyalarında program `"Error
"` mesajı vererek çıkmalıdır.
- Global değişken kullanımı önerilmez.

## 🧠 Kullanılan Fonksiyonlar

- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- `MiniLibX` kütüphanesindeki tüm fonksiyonlar
- `libft` (izinli)
- `ft_printf` veya eşdeğeri (kendi yazılmış)

## 📄 Notlar

- Bu versiyon **yalnızca zorunlu kısmı** kapsamaktadır, bonus özellikler içermez.
- Kodlar `Norminette` standartlarına uygundur.
- Harita geçerliliği kontrol edilmekte ve geçersizse hata döndürülmektedir.
