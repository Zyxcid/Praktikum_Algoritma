![Job Sheet 11](https://github.com/Zyxcid/Praktikum_Algoritma/blob/main/Images/JS11.png)

## [Dasar-dasar File Handling dalam Bahasa C](https://www.geeksforgeeks.org/basics-file-handling-c/)  

Perlu diingat **File di komputer ada 2 jenis**  

![2 Jenis File](https://media.geeksforgeeks.org/wp-content/uploads/20230503150409/Types-of-Files-in-C.webp)  

## Operasi File C  
Operasi file C mengacu pada berbagai kemungkinan operasi yang dapat kita lakukan pada file di C seperti:

Membuat file baru – fopen() dengan atribut sebagai “a” atau “a+” atau “w” atau “w+”  
Membuka file yang ada – fopen()  
Membaca dari file – fscanf() atau fgets()  
Menulis ke file – fprintf() atau fputs()  
Memindahkan ke lokasi tertentu dalam file – fseek(), rewind()  
Menutup file – fclose()  

## File Pointer di C
Pointer file adalah referensi ke posisi tertentu dalam file yang dibuka. Hal ini digunakan dalam penanganan file untuk melakukan semua operasi file seperti membaca, menulis, menutup, dll.  
Kita menggunakan makro FILE untuk mendeklarasikan variabel pointer file. Makro FILE didefinisikan di dalam file header <stdio.h>.
```
FILE* pointer_name;
```
## Buka File di C
Untuk membuka file di C, fungsi [fopen()](https://www.geeksforgeeks.org/c-fopen-function-with-examples/) digunakan dengan nama file atau jalur file beserta mode akses yang diperlukan.

Sintaks fopen()
```
FILE* fopen(const char *nama_file, const char *mode_akses);
```
### Mode fopen
![Mode fopen](https://1.bp.blogspot.com/-23tdI4GTAW0/YUXbeQ5HtJI/AAAAAAAAIik/nMHADtQ0ubAXs7rNQH94GK0cuMAI76sLwCLcBGAsYHQ/s600/tabel2.png)

## Buat File di C
Fungsi fopen() tidak hanya dapat membuka file tetapi juga dapat membuat file jika belum ada. Untuk itu kita harus menggunakan mode yang memungkinkan pembuatan file jika tidak ditemukan seperti w, w+, wb, wb+, a, a+, ab, dan ab+.  
```
FILE *fptr;
fptr = buka("namafile.txt", "w");
```

## Membaca Dari File
Operasi pembacaan file di C dapat dilakukan menggunakan fungsi fscanf() atau fgets(). Kedua fungsi tersebut menjalankan operasi yang sama seperti scanf dan get tetapi dengan parameter tambahan, file pointer.  

## Menulis ke File
Operasi penulisan file dapat dilakukan oleh fungsi fprintf() dan fputs() yang mirip dengan operasi baca.  

## Menutup File
Fungsi fclose() digunakan untuk menutup file. Setelah operasi file berhasil, Anda harus selalu menutup file untuk menghapusnya dari memori.  
```
Sintaks fclose()
fclose(file_pointer);
```
