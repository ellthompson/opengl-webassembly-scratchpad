# OpenGL WebAssembly Scratch Pad

A simple way to begin writing & testing shader code in the browser

## How to run the project

* Ensure all appropriate .obj models are placed in `./models/` at the root of this project directory. Check `./src/cpp/renderer.cpp` and pass the required model name to the loadModel() function.
* Download the [c++ libraries include folder](https://drive.google.com/file/d/1UDpir6xY0SoGI6yOZ7bpwN25ycvgq8Nh/view?usp=sharing) and place it at the root of the project directory
* Install the emscripten compiler using the following link https://emscripten.org/docs/getting_started/Tutorial.html
* Run the emscripten compiler at the root of this directory using the `./build.sh` command
* Files are served via a simple python server. Run this using the following command: `python -m SimpleHTTPServer 8080`
* Go to http://localhost:8080/ in your browser
