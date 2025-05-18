# L-System Drawer

A graphical application for visualizing various L-system fractals using MFC.

## About

L-System Drawer visualizes different fractal patterns including:
- Koch Snowflake
- Sierpinski Triangle 
- Dragon Curve
- Hilbert Curve
- Hosper Curve
- Lévy C Curve
- Minkovskiy Curve
- Pifagor Tree

Each fractal is implemented using Lindenmayer systems (L-systems), a mathematical formalism that uses recursive string rewriting to generate complex patterns.

## Architecture

The application uses an MFC-based UI with an object-oriented design:
- `BaseLine`: Abstract base class for all fractal lines
- Specialized implementations for each fractal type
- Interface-based drawing primitives with MFC implementation

## Building

### Windows (Visual Studio)
```bash
mkdir build && cd build
cmake -G "Visual Studio 16 2019" ..
```
Then either:
1. Open the generated solution file in Visual Studio
2. Build using VS interface

Or build directly with CMake:
```bash
cmake --build . --config Release
```

### Linux (Core Library and Tests)
```bash
mkdir build && cd build
cmake -DCMAKE_CXX_COMPILER=g++ ..
cmake --build .
ctest # Run the tests
```

Full GUI support on Linux is under development, but the core mathematical utilities and tests are now compatible with Linux/GCC.

## Testing

Run the basic tests with:
```bash
cd tests
ctest
```

## Future Development

- [ ] Cross-platform support using portable drawing libraries
- [ ] Custom L-system rule definitions
- [ ] More fractal types and visualization options
- [ ] Parameter controls for angle and iteration depth

## License

[MIT License](LICENSE)