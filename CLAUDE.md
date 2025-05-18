# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

L_system_draw is a Windows MFC application for drawing various L-system fractals. The application visualizes different fractal patterns including Koch, Dragon, Hilbert, Sierpinski, Hosper, and others.

## Architecture

### Key Components

- **BaseLine**: Abstract base class for all fractal line types
  - Uses PIMPL pattern with `BaseLineImpl`
  - Provides core drawing functionality and state management

- **InterfacePaintPrimitive**: Contains abstract interfaces for drawing
  - `IPen<T>`, `IBrush<T>`, `IRect<T>`, `IPaintDC<T,U,P,R>`

- **MFCPaintPrimitive**: Concrete implementations of the interfaces using MFC
  - `MFCPen`, `MFCBrush`, `MFCRect`, `MFCPaintDC`

- **Fractal Implementations**: Various classes derived from BaseLine
  - `KochLine`, `DragonLine`, `HilbertLine`, `SierpinskiLine`, etc.
  - Each implements its own recursive drawing algorithm via the `Draw()` method

### Design Patterns

1. **Interface-based design**: Abstract drawing operations through interfaces
2. **PIMPL (Pointer to Implementation)**: Hides implementation details in BaseLine
3. **Template-based interfaces**: All drawing interfaces are templated
4. **Inheritance hierarchy**: All fractal types inherit from BaseLine

## Build Information

- **Build Platform**: Visual Studio (VC++ 14.0/Visual Studio 2015)
- **Target Platforms**: Win32 and x64
- **Character Set**: Unicode
- **Build Configurations**: Debug and Release
- **MFC Library**: Dynamic MFC libraries

## Development Guidelines

When modifying existing fractal implementations or adding new ones:

1. Ensure new fractal classes inherit from `BaseLine`
2. Implement the `Draw()` method with the specific L-system rules
3. Follow the existing patterns for managing coordinate transformations
4. Respect the interface-based drawing approach when implementing new drawing features