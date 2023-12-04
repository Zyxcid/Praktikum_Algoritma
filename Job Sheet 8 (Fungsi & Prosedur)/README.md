![Job Sheet 8](https://github.com/Zyxcid/Praktikum_Algoritma/blob/main/Images/JS8.png)

## [Fungsi dalam bahasa C](https://www.geeksforgeeks.org/c-functions/)  
Fungsi adalah sub-program yang bisa digunakan kembali baik di dalam
program itu sendiri, maupun di program yang lain.  

## Bagaimana Cara Kerja Fungsi C?
Cara kerja fungsi C dapat dipecah menjadi langkah-langkah berikut seperti yang disebutkan di bawah ini:

+ **Mendeklarasikan suatu fungsi**: Mendeklarasikan suatu fungsi adalah langkah dimana kita mendeklarasikan suatu fungsi. Di sini kita mendefinisikan tipe kembalian dan parameter fungsi.  
+ **Mendefinisikan suatu fungsi**:   
+ **Memanggil fungsi**: Memanggil fungsi adalah langkah di mana kita memanggil fungsi dengan meneruskan argumen dalam fungsi tersebut.  
+ **Mengeksekusi fungsi**: Mengeksekusi fungsi adalah langkah di mana kita bisa menjalankan semua pernyataan di dalam fungsi untuk mendapatkan hasil akhir.  
+ **Mengembalikan nilai**: Mengembalikan nilai adalah langkah dimana nilai terhitung setelah eksekusi fungsi dikembalikan. Keluar dari fungsi adalah langkah terakhir di mana semua memori yang dialokasikan untuk variabel, fungsi, dll dimusnahkan sebelum memberikan kontrol penuh ke fungsi utama.  

## [Fungsi Rekursif](https://www.geeksforgeeks.org/c-recursion/) 
Fungsi rekursif adalah fungsi yang memanggil dirinya sendiri.  
![Fungsi rekursif](https://media.geeksforgeeks.org/wp-content/uploads/20230626150540/recursion-tree.png)

## [Teknik Passing dalam Bahasa C](https://www.geeksforgeeks.org/parameter-passing-techniques-in-c-cpp/?ref=lbp)  
### By Value:  
Perubahan yang dilakukan pada parameter formal tidak dikirimkan kembali ke pemanggil. Modifikasi apa pun pada variabel parameter formal di dalam fungsi atau metode yang dipanggil hanya memengaruhi **lokasi penyimpanan terpisah** dan tidak akan tercermin dalam parameter sebenarnya di lingkungan pemanggil. Metode ini juga disebut **call by value**.  
![Pass by value](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Call-By-Value.png)  
### By Reference:  
Perubahan yang dilakukan pada parameter formal dikirimkan kembali ke pemanggil melalui penerusan parameter. Setiap perubahan pada parameter formal tercermin dalam parameter aktual di lingkungan pemanggilan karena parameter formal menerima referensi (atau penunjuk) ke **data aktual**. Metode ini disebut juga **call by reference**. Cara ini efisien dalam ruang dan waktu.  
![Pass by reference](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Call-By-Reference.png)  
