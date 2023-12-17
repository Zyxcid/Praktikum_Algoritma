![Job Sheet 3](https://github.com/Zyxcid/Praktikum_Algoritma/blob/main/Images/JS3.png)
## [Variabel](https://www.geeksforgeeks.org/variables-in-c/)
![ilustrasi variabel dalam bahasa C](https://s3.studytonight.com/tutorials/uploads/pictures/1632807040-.png)  
Variabel dalam C adalah lokasi memori dengan beberapa nama yang membantu menyimpan beberapa bentuk data dan mengambilnya saat diperlukan.  
Kita dapat menyimpan berbagai jenis data dalam variabel dan menggunakan kembali variabel yang sama untuk menyimpan beberapa data lain berapa kali pun.  
  
### Pendeklarasian Variabel
```
tipe_data nama_variabel = nilai ; // mendefinisikan variabel tunggal   
 atau   
tipe_data nama_variabel1, nama_variabel2; // mendefinisikan banyak variabel  
```
beberapa catatan untuk penamaan variabel:
* Nama variabel hanya boleh berisi huruf, angka, dan garis bawah.
* Nama variabel harus diawali dengan alfabet atau garis bawah saja. Itu tidak bisa dimulai dengan angka.
* Spasi putih tidak diperbolehkan dalam nama variabel.
* Nama variabel tidak boleh berupa kata atau kata kunci khusus apa pun.

![Aturan penamaan variabel](https://media.geeksforgeeks.org/wp-content/uploads/20221202181520/Cvariables2.png)

### Jenis Variabel C
+ Variabel Lokal - Variabel lokal di C adalah variabel yang dideklarasikan di dalam suatu fungsi atau blok kode.
Cakupannya terbatas pada blok atau fungsi yang dideklarasikannya.  
+ Variabel Global - Variabel Global di C adalah variabel yang dideklarasikan di luar fungsi atau blok kode.
Ruang lingkupnya adalah keseluruhan program yaitu kita dapat mengakses variabel global dimana saja dalam program C setelah dideklarasikan.

## [konstanta](https://www.geeksforgeeks.org/constants-in-c/)
Konstanta dalam C adalah variabel read-only yang nilainya tidak dapat diubah setelah didefinisikan.  
Kita dapat mendeklarasikan variabel konstan menggunakan kata kunci `const`.  
### Pendeklarasian Konstanta
```
const tipe_data nama_variabel = nilai;  
```
![Pendeklarasian Konstanta dalam bahasa C](https://media.geeksforgeeks.org/wp-content/uploads/20230306220005/how-to-declare-constants-in-c.png)  

## [Tipe Data](https://www.geeksforgeeks.org/data-types-in-c/)  
Setiap variabel di C memiliki tipe data. Tipe data yang dapat disimpan oleh variabel seperti bilangan bulat, karakter, desimal, dll.   
Setiap tipe data memerlukan jumlah memori yang berbeda dan memiliki beberapa operasi spesifik yang dapat dilakukan terhadapnya.  
Tipe data merupakan kumpulan data yang nilainya mempunyai nilai tetap.  

### Jenis Tipe Data  
- **Tipe Data Primitif** - Tipe data primitif adalah tipe data paling dasar yang digunakan untuk merepresentasikan nilai sederhana seperti bilangan bulat, float, karakter, dll.  
- **Tipe data Turunan** - Tipe data yang diturunkan dari tipe data primitif atau bawaan disebut sebagai Tipe Data Turunan.  
- **Tipe Data Buatan Pengguna**	- Tipe data yang ditentukan pengguna ditentukan oleh pengguna itu sendiri.  

![Beberapa Tipe Data dalam bahasa C](https://media.geeksforgeeks.org/wp-content/uploads/20220808115138/DatatypesInC.jpg)
