::File Compression Algorithms: Implementation And Comparisons::

Drive Link for video:https://drive.google.com/drive/u/0/folders/1WGlCyOIuyLYyLCYWPpSIzql1t42z2PQO

To run:  
Clone the project onto local computer.  
(All the executable files are also uploaded. Simply you can clone and run without compiling)  

To run Huffman:  
Go to Huffman-Encoding folder and simply run in terminal:  
to compress: .\compress.exe  
to decompress: .\decompress.exe  

To run LZW:  
Go to LZW-Encoding folder and simply run in terminal:  
to compress:  .\lzw -c <input file name> <output file name>  
to decompress:  .\lzw -d <input file name> <output file name>  
  
To run PPM:
Go to PPM-Encoding folder and simply run in terminal:  
to compress: .\ppm c <input file name> <output file name>  
to decompress: .\ppm d <input file name> <output file name>  
    
To compile the files:  
  
For Huffman-Go to Huffman-Encoding Folder and in terminal type:   
For compression: g++ compress.cpp -o compress.exe  
For decompression: g++ decompress.cpp -o decompress.exe  
  
For LZW- Go to LZW-Encoding Folder and in terminal type: g++ lzw.cpp -o lzw -O3  
  
For PPM- Go to PPM-Encoding Folder and in terminal type: g++ -o ppm *.cpp  
