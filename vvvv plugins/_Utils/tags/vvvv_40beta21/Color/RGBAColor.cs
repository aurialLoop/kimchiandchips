/*
 * 
 * the c# vvvv color library
 * 
 * 
 */

using System;
using System.Runtime.InteropServices;
using System.Drawing;
using VVVV.Utils.VMath;

namespace VVVV.Utils.VColor
{
	/// <summary>
	/// 256-bit color struct, compatible with vvvv colors.
	/// There is an implicit cast to the C# Color type and an explictit cast from C# color to RGBAColor.
	/// Aswell as implicit casts from and to Vector4D.
	/// </summary>
	[StructLayout(LayoutKind.Sequential)]
	public struct RGBAColor
	{
		#region data fields

		/// <summary>
		/// The Red data field
		/// </summary>
		public double R;
		/// <summary>
		/// The Green data field
		/// </summary>
		public double G;
		/// <summary>
		/// The Blue data field
		/// </summary>
		public double B;
		/// <summary>
		/// The Alpha data field
		/// </summary>
		public double A;
		
		#endregion data fields
		
		#region constructor, properties
		
		/// <summary>
		/// vvvv color constructor
		/// </summary>
		/// <param name="Red">red component, 0..1</param>
		/// <param name="Green">green component, 0..1</param>
		/// <param name="Blue">blue component, 0..1</param>
		/// <param name="Alpha">alpha component, 0..1</param>
		public RGBAColor(double Red, double Green, double Blue, double Alpha)
		{
			R = Red;
			G = Green;
			B = Blue;
			A = Alpha;
		}
	
		/// <summary>
		/// C# color type property, can be used for conversion
		/// Note, that there is also implicit casting to C# color, and explicit casting from C# color
		/// </summary>
		public Color Color
		{
			get {return Color.FromArgb((int)(A*255), (int)(R*255), (int)(G*255), (int)(B*255));}
			set {A = value.A / 255.0; R = value.R / 255.0; G = value.G / 255.0; B = value.B / 255.0;}
		}
		
		/// <summary>
		/// Get string name for the color
		/// </summary>
		/// <returns>Color name</returns>
		public override string ToString()
		{
			return Color.Name;		
		}
		
		#endregion constructor, properties
		
		#region casting operators
		
		//4d-vector
		
		/// <summary>
		/// Casts a color to a 4d-vector
		/// </summary>
		/// <param name="a">color to cast</param>
		/// <returns>4d-vector with same values than the input color</returns>
		public static implicit operator Vector4D(RGBAColor a)
        {
			return new Vector4D(a.R, a.G, a.B, a.A);
        }
		
		/// <summary>
		/// Casts a 4d-vector to a color
		/// </summary>
		/// <param name="a">4d-vector to cast</param>
		/// <returns>color with same values like than input 4d-vector</returns>
		public static implicit operator RGBAColor(Vector4D a)
        {
			return new RGBAColor(a.x, a.y, a.z, a.w);
        }
		
		/// <summary>
		/// Casts a C# color to a color
		/// </summary>
		/// <param name="C">C# color to cast</param>
		/// <returns>Same Color than the input C# color</returns>
		public static implicit operator RGBAColor(Color C)
        {
			return new RGBAColor(C.R / 255.0, C.G / 255.0, C.B / 255.0, C.A / 255.0);
        }
		
		/// <summary>
		/// Explicit cast from color to C# color
		/// </summary>
		/// <param name="C">color to cast</param>
		/// <returns>C# color with closest values to the input the color</returns>
		public static explicit operator Color(RGBAColor C)
        {
			return Color.FromArgb((int)(C.A*255), (int)(C.R*255), (int)(C.G*255), (int)(C.B*255));
        }
		
		#endregion casting operators
		
		#region unary operators
			
		/// <summary>
		/// + color, makes no changes to a color
		/// </summary>
		/// <param name="C"></param>
		/// <returns>Input color C unchanged</returns>
		public static RGBAColor operator +(RGBAColor C)
		{
			return C;
		}
		
		/// <summary>
		/// - color, flips the sign off all color components
		/// </summary>
		/// <param name="C"></param>
		/// <returns>New color with all components of C negatived</returns>
		public static RGBAColor operator -(RGBAColor C)
		{
			return new RGBAColor( -C.R, -C.G, -C.B, -C.A);
		}
		
		/// <summary>
		/// ! color, calculates the complementary color
		/// </summary>
		/// <param name="C"></param>
		/// <returns>Complementary color to the input color C</returns>
		public static RGBAColor operator !(RGBAColor C)
		{
			return new RGBAColor( 1-C.R, 1-C.G, 1-C.B, 1);
		}
		
		/// <summary>
		/// ~ color, calculates the brighness of a color with the formula 0.222 * R + 0.707 * G + 0.071 * B
		/// </summary>
		/// <param name="C"></param>
		/// <returns>Brightness value of the input color C</returns>
		public static double operator ~(RGBAColor C)
		{
			return 0.222 * C.R + 0.707 * C.G + 0.071 * C.B;
		}	
		
		#endregion unary operators
		
		#region binary operators
		
		/// <summary>
		/// Adds the color components of two colors
		/// </summary>
		/// <param name="C1"></param>
		/// <param name="C2"></param>
		/// <returns>Sum of two colors</returns>
		public static RGBAColor operator +(RGBAColor C1, RGBAColor C2)
		{
			return new RGBAColor(C1.R + C2.R, C1.G + C2.G, C1.B + C2.B, C1.A + C2.A);
		}
		
		/// <summary>
		/// Subtracts the color components of two colors
		/// </summary>
		/// <param name="C1"></param>
		/// <param name="C2"></param>
		/// <returns>Difference of two colors</returns>
		public static RGBAColor operator -(RGBAColor C1, RGBAColor C2)
		{
			return new RGBAColor(C1.R - C2.R, C1.G - C2.G, C1.B - C2.B, C1.A - C2.A);
		}
		
		/// <summary>
		/// Multiplies a color with a factor
		/// </summary>
		/// <param name="C"></param>
		/// <param name="factor"></param>
		/// <returns>Color multiplied by the factor</returns>
		public static RGBAColor operator *(RGBAColor C, double factor)
		{
			return new RGBAColor(C.R * factor, C.G * factor, C.B * factor, C.A * factor);
		}
		
		/// <summary>
		/// Multiplies a factor with a color
		/// </summary>
		/// <param name="factor"></param>
		/// <param name="C"></param>
		/// <returns>Color multiplied by the factor</returns>
		public static RGBAColor operator *(double factor, RGBAColor C)
		{
			return new RGBAColor(C.R * factor, C.G * factor, C.B * factor, C.A * factor);
		}
		
		/// <summary>
		/// Multiplies two colors, RGBA component wise
		/// </summary>
		/// <param name="C1"></param>
		/// <param name="C2"></param>
		/// <returns>Color C1 multiplied by color C2</returns>
		public static RGBAColor operator *(RGBAColor C1, RGBAColor C2)
		{
			return new RGBAColor(C1.R * C2.R, C1.G * C2.G, C1.B * C2.B, C1.A * C2.A);
		}
		
		#endregion binary operators
	}
}
