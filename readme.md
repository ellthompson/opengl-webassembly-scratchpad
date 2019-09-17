# OpenGL WebAssembly Scratch Pad

A simple way to begin writing & testing shader code in the browser

## How to run the project

* Ensure all appropriate .obj models are placed in `./models/` at the root of this project directory. Check `./src/cpp/renderer.cpp` and pass the required model name to the loadModel() function.
* Download the [c++ libraries include folder](https://drive.google.com/file/d/1UDpir6xY0SoGI6yOZ7bpwN25ycvgq8Nh/view?usp=sharing) and place it at the root of the project directory
* Install the [emscripten compiler](https://emscripten.org/docs/getting_started/Tutorial.html)
* Install the [lzz preprocessor](https://www.lazycplusplus.com)
* Run the emscripten compiler at the root of this directory using the `./build.sh` command
* Files are served via a simple python server. Run this using the following command: `python -m SimpleHTTPServer 8080`
* Go to http://localhost:8080/build/ in your browser

## Contributing C++ code

### Adding new C++ files

After adding a new `.cpp` file to the project, you must let the emscripten compiler know about its prescence. To do this add the path of the new file into the `em++` command within the `./build.sh` file.

### Lazy C++ Class Preprocessing

The project uses the lazy c++ preprocessor to generate any class header + source files from a single .lzz file. Any class folders which contain `.cpp`, `.h` & `.lzz` files must be built using this preprocessor. In these instances you should only edit the `.lzz` files and let the preprocessor build the `.cpp` & `.h` files. The lazy preprocessor is ran as part of the `./build.sh` script.

If you add a new class `.lzz` file, you must tell the `./build.sh` script to preprocess it by adding the following line to the script: `lzz src/cpp/<namespace_name>/<class_name>.lzz`
