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

### Visual Studio
1. Open `L_system_draw.vcxproj` in Visual Studio
2. Select configuration (Debug/Release) and platform (x86/x64)
3. Build solution

### CMake (New!)
```bash
mkdir build && cd build
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
```

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