# Contributing to L-System Drawer

Thank you for your interest in contributing to L-System Drawer! This guide will help you get started.

## Development Environment

### Prerequisites
- Visual Studio 2015 or later (for Windows/MFC development)
- CMake 3.15 or later (for build system generation)
- GoogleTest (automatically fetched by CMake if testing is enabled)

### Building with CMake
```bash
mkdir build && cd build
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
```

## Testing

We use GoogleTest for unit testing. Tests are located in the `tests/` directory.

### Running Tests
```bash
cd build
ctest -C Release
```

### Writing Tests

When adding new functionality or fixing bugs, please include appropriate tests:

1. Create or modify test files in the `tests/` directory
2. Tests should be focused and test one specific functionality
3. Mock dependencies like MFC objects when testing core functionality

## Pull Request Process

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## Coding Style

- Follow the existing coding style in the repository
- Use consistent indentation (4 spaces)
- Use descriptive variable and function names
- Include comments for complex logic
- Use PIMPL and other design patterns where appropriate

## Adding New Fractals

To add a new fractal type:

1. Create a new class derived from `BaseLine`
2. Implement the `Draw()` method with your L-system rules
3. Add any necessary helper methods
4. Register the new fractal type in the UI
5. Add tests for the new functionality