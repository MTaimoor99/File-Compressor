# File-Compressor
This is a GUI application that compresses a text file using the Huffman Algorithm. Technologies used are Visual Studio, C++ and the .NET Framework.

# Note
Before downloading this project, make sure you have Visual Studio 2022 downloaded on your system. Also make sure that you have downloaded C++ and .NET Framework workloads in your Visual Studio to run this project.

# How To Install
1. Download the Huffman file as a zip.
2. Extract the Huffman folder from the zip file.
3. Go in Huffman>Huffman.sln in order to run this project on Visual Studio.

# How Does the Project Work
1. Press the "Run" button on Visual Studio. This will display a GUI.
2. Type the name of the file with the extension into the searchbar. For example if you want to compress a text file by the name of "Sample", you will type Sample.txt in the search bar.
3. Make sure that the file is already present in the project's directory.
4. Press the "Compress" button. This will return a file by the name of "Compressed.txt" which will contain the compressed data.
5. To decompress the file, type "Compressed.txt" in the search bar, and press the "Decompress" button. This will return a file called "Decompressed.txt" which will contan the contents of the original file.
6. To use the application again, close it, delete the compressed and decompressed text files, and then run it again to compress or decompress your deisred text file again.

#Warnings
1. This application will only work on files having the ".txt" extension.
2. Make sure your text file is in the project directory.
3. Make sure to delete the "Compressed.txt" and "Decompressed.txt" text files and closing the application before running it again.
