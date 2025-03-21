# push_swap

Bu proje, integer veri içeren bir `stack a`'yı mümkün olan **en az hamle** sayısıyla sıralamayı amaçlamaktadır. Bu işlem yalnızca belirli aksiyonlarla yapılabilir ve sıralama işlemi boyunca bu aksiyonların listesi yazdırılır. Projede ayrıca bu işlemleri doğrulamak için bir `checker` programı da yazılmıştır.

## 📁 İçerik

- `push_swap`: Verilen integerları sıralamak için gereken aksiyonları çıktılar.
- `checker`: `push_swap` çıktısının doğru sıralama yapıp yapmadığını kontrol eder.

## ⚙️ Derleme

Tüm dosyalar `Makefile` ile derlenebilir.

```bash
make        # push_swap derlenir
make bonus  # checker programı da dahil edilir
make clean
make fclean
make re
```

## 🧠 Kullanım

```bash
./push_swap 3 2 1 0
```

Bu komut, sıralamak için gereken aksiyonları stdout’a yazdırır.

```bash
./push_swap 3 2 1 0 | ./checker 3 2 1 0
```

Bu komut ise checker ile doğrulama yapar. Eğer her şey doğruysa `OK`, aksi halde `KO` yazdırır.

## 📌 push_swap Özellikleri

- Girilen integerlar sıralanmışsa hiçbir çıktı verilmez.
- Hatalı argüman varsa `Error` yazdırılır.
- Amaç, verilen integerları `stack a` içinde artan şekilde sıralamaktır.
- `stack b` yalnızca geçici taşıma amaçlı kullanılır.
- Aksiyonlar: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`

## ⭐ Bonus: checker

- `checker` programı, stdin'den aksiyonları okur ve `stack a`'yı sıralayıp sıralamadığını kontrol eder.
- Eğer `stack a` sıralı ve `stack b` boş ise `OK`, değilse `KO` yazdırır.
- Geçersiz aksiyonlarda veya hatalı argümanlarda `Error` yazdırır.

## 🎯 Performans

Aşağıdaki limitleri karşılayacak şekilde optimize edilmiştir:

- 100 sayı < 700 aksiyon
- 500 sayı < 5500 aksiyon

Bu limitleri karşılamıyorsa projeniz tam puan alamaz ve bonus değerlendirmeye alınmaz.

## 📂 Ekstra Bilgi

Bu proje, 42 intranetinde yer alan `checker_linux` adlı programla birlikte test edilmelidir. Bu nedenle, bu repoda `checker_linux` dosyası da `push_swap` ile birlikte paylaşılmıştır. Böylece değerlendirme öncesinde test yapmak kolaylaşır.

## 🧪 Test Örnekleri

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK

ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
```

## 🛡 Kurallar

- Bellek sızıntısı olmamalıdır (valgrind ile test edilmiştir).
- `Norminette` kurallarına tamamen uygundur.
- Global değişken **KULLANILMAMIŞTIR**.
- Libft kullanımı serbesttir.
