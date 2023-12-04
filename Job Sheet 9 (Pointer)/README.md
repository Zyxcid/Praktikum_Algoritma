![Job Sheet 9](https://github.com/Zyxcid/Praktikum_Algoritma/blob/main/Images/JS9.png)

[Pointer](https://www.geeksforgeeks.org/c-pointers/) didefinisikan sebagai tipe data turunan yang dapat menyimpan alamat variabel C lain atau **lokasi memori**. Kita dapat mengakses dan memanipulasi data yang disimpan di lokasi memori tersebut menggunakan pointer.  

![Cara pointer bekerja](https://www.geeksforgeeks.org/wp-content/uploads/How-Pointer-Works-In-C.png)

Pointer digunakan secara ekstensif di C dan C++ untuk tiga tujuan utama: 
* Untuk mengalokasikan objek baru pada timbunan;
* Untuk meneruskan fungsi ke fungsi lain;
* Untuk melakukan iterasi atas elemen dalam array atau struktur data lainnya.

### Bagaimana Cara Menggunakan Pointer?
Penggunaan pointer di C dapat dibagi menjadi tiga langkah:

- Deklarasi Pointer
   Dalam deklarasi pointer, kita hanya mendeklarasikan pointer tetapi tidak menginisialisasinya. Untuk mendeklarasikan sebuah pointer, kita menggunakan operator dereferensi ( * ) sebelum namanya.  
Contoh:
> int * ptr ;  

- Inisialisasi Pointer
   Inisialisasi pointer adalah proses dimana kita memberikan beberapa nilai awal ke variabel pointer. Kami biasanya menggunakan operator alamat ( & ) untuk mendapatkan alamat memori suatu variabel dan kemudian menyimpannya dalam variabel penunjuk.  
Contoh:
>int var = 10;  
>int * ptr ;  
>ptr = & var;   
