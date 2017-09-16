#pragma once

namespace fractal_lines{

	template<typename T>
	class IPen {
	public:
		virtual void Reset() = 0;
		virtual T* GetPen() const = 0;
		virtual bool IsExist() const = 0;
	};

	template<typename T>
	class IBrush {
	public:
		virtual void Reset() = 0;
		virtual T* GetBrush() const = 0;
		virtual bool IsExist() const = 0;
	};

	template<typename T>
	class IRect {
	public:
		virtual T* GetRect() const = 0;
		virtual bool IsExist() const = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};
	
	template<typename T, typename U, typename P, typename R>
	class IPaintDC {
	public:
		virtual void SetDefaultBack(const IRect<R>&) = 0;
		virtual void SetNewBack(const IBrush<T>&, U&) = 0;
		virtual void MoveTo(const int& x, const int& y) = 0;
		virtual void LineTo(const int& x, const int& y) = 0;
		virtual void SetPen(const IPen<P>&) = 0;
		virtual bool IsExist() const = 0;
	};
}
