#ifndef __GLSLPP_SWIZZLE_H
#define __GLSLPP_SWIZZLE_H

#define SWIZZLE_OP(TYPE, SWIZZLE) inline TYPE SWIZZLE () const { TYPE result; result.SetType(Temporary); result.m_TemporaryInitialization = xs("%.%", Definition(), SwizzleExtension(Swizzle::SWIZZLE)); return result; }

#ifdef __GLC_ENABLE_SWIZZLE_MACROS

#endif


namespace GLSLPP
{

	enum class Swizzle
	{
		NoSwizzle,

		// 1 component (xyzw)
		x, y, z, w,

		// 2 component (xyzw)
		xx, xy, xz, xw,
		yx, yy, yz, yw,
		zx, zy, zz, zw,
		wx, wy, wz, ww,

		// 3 component (xyzw)
		xxx, xxy, xxz, xxw, xyx, xyy, xyz, xyw, xzx, xzy, xzz, xzw, xwx, xwy, xwz, xww,
		yxx, yxy, yxz, yxw, yyx, yyy, yyz, yyw, yzx, yzy, yzz, yzw, ywx, ywy, ywz, yww,
		zxx, zxy, zxz, zxw, zyx, zyy, zyz, zyw, zzx, zzy, zzz, zzw, zwx, zwy, zwz, zww,
		wxx, wxy, wxz, wxw, wyx, wyy, wyz, wyw, wzx, wzy, wzz, wzw, wwx, wwy, wwz, www,

		// 4 component (xyzw)
		xxxx, xxxy, xxxz, xxxw, xxyx, xxyy, xxyz, xxyw, xxzx, xxzy, xxzz, xxzw, xxwx, xxwy, xxwz, xxww,
		xyxx, xyxy, xyxz, xyxw, xyyx, xyyy, xyyz, xyyw, xyzx, xyzy, xyzz, xyzw, xywx, xywy, xywz, xyww,
		xzxx, xzxy, xzxz, xzxw, xzyx, xzyy, xzyz, xzyw, xzzx, xzzy, xzzz, xzzw, xzwx, xzwy, xzwz, xzww,
		xwxx, xwxy, xwxz, xwxw, xwyx, xwyy, xwyz, xwyw, xwzx, xwzy, xwzz, xwzw, xwwx, xwwy, xwwz, xwww,

		yxxx, yxxy, yxxz, yxxw, yxyx, yxyy, yxyz, yxyw, yxzx, yxzy, yxzz, yxzw, yxwx, yxwy, yxwz, yxww,
		yyxx, yyxy, yyxz, yyxw, yyyx, yyyy, yyyz, yyyw, yyzx, yyzy, yyzz, yyzw, yywx, yywy, yywz, yyww,
		yzxx, yzxy, yzxz, yzxw, yzyx, yzyy, yzyz, yzyw, yzzx, yzzy, yzzz, yzzw, yzwx, yzwy, yzwz, yzww,
		ywxx, ywxy, ywxz, ywxw, ywyx, ywyy, ywyz, ywyw, ywzx, ywzy, ywzz, ywzw, ywwx, ywwy, ywwz, ywww,

		zxxx, zxxy, zxxz, zxxw, zxyx, zxyy, zxyz, zxyw, zxzx, zxzy, zxzz, zxzw, zxwx, zxwy, zxwz, zxww,
		zyxx, zyxy, zyxz, zyxw, zyyx, zyyy, zyyz, zyyw, zyzx, zyzy, zyzz, zyzw, zywx, zywy, zywz, zyww,
		zzxx, zzxy, zzxz, zzxw, zzyx, zzyy, zzyz, zzyw, zzzx, zzzy, zzzz, zzzw, zzwx, zzwy, zzwz, zzww,
		zwxx, zwxy, zwxz, zwxw, zwyx, zwyy, zwyz, zwyw, zwzx, zwzy, zwzz, zwzw, zwwx, zwwy, zwwz, zwww,

		wxxx, wxxy, wxxz, wxxw, wxyx, wxyy, wxyz, wxyw, wxzx, wxzy, wxzz, wxzw, wxwx, wxwy, wxwz, wxww,
		wyxx, wyxy, wyxz, wyxw, wyyx, wyyy, wyyz, wyyw, wyzx, wyzy, wyzz, wyzw, wywx, wywy, wywz, wyww,
		wzxx, wzxy, wzxz, wzxw, wzyx, wzyy, wzyz, wzyw, wzzx, wzzy, wzzz, wzzw, wzwx, wzwy, wzwz, wzww,
		wwxx, wwxy, wwxz, wwxw, wwyx, wwyy, wwyz, wwyw, wwzx, wwzy, wwzz, wwzw, wwwx, wwwy, wwwz, wwww,

		// 1 component (rgba)
		r = x, g = y, b = z, a = w,

		// 2 component (rgba)
		rr = xx, rg = xy, rb = xz, ra = xw,
		gr = yx, gg = yy, gb = yz, ga = yw,
		br = zx, bg = zy, bb = zz, ba = zw,
		ar = wx, ag = wy, ab = wz, aa = ww,

		// 3 component (rgba)
		rrr = xxx, rrg = xxy, rrb = xxz, rra = xxw, rgr = xyx, rgg = xyy, rgb = xyz, rga = xyw,
		rbr = xzx, rbg = xzy, rbb = xzz, rba = xzw, rar = xwx, rag = xwy, rab = xwz, raa = xww,
		grr = yxx, grg = yxy, grb = yxz, gra = yxw, ggr = yyx, ggg = yyy, ggb = yyz, gga = yyw,
		gbr = yzx, gbg = yzy, gbb = yzz, gba = yzw, gar = ywx, gag = ywy, gab = ywz, gaa = yww,
		brr = zxx, brg = zxy, brb = zxz, bra = zxw, bgr = zyx, bgg = zyy, bgb = zyz, bga = zyw,
		bbr = zzx, bbg = zzy, bbb = zzz, bba = zzw, bar = zwx, bag = zwy, bab = zwz, baa = zww,
		arr = wxx, arg = wxy, arb = wxz, ara = wxw, agr = wyx, agg = wyy, agb = wyz, aga = wyw,
		abr = wzx, abg = wzy, abb = wzz, aba = wzw, aar = wwx, aag = wwy, aab = wwz, aaa = www,

		// 4 component (rgba)
		rrrr = xxxx, rrrg = xxxy, rrrb = xxxz, rrra = xxxw, rrgr = xxyx, rrgg = xxyy, rrgb = xxyz, rrga = xxyw,
		rrbr = xxzx, rrbg = xxzy, rrbb = xxzz, rrba = xxzw, rrar = xxwx, rrag = xxwy, rrab = xxwz, rraa = xxww,
		rgrr = xyxx, rgrg = xyxy, rgrb = xyxz, rgra = xyxw, rggr = xyyx, rggg = xyyy, rggb = xyyz, rgga = xyyw,
		rgbr = xyzx, rgbg = xyzy, rgbb = xyzz, rgba = xyzw, rgar = xywx, rgag = xywy, rgab = xywz, rgaa = xyww,
		rbrr = xzxx, rbrg = xzxy, rbrb = xzxz, rbra = xzxw, rbgr = xzyx, rbgg = xzyy, rbgb = xzyz, rbga = xzyw,
		rbbr = xzzx, rbbg = xzzy, rbbb = xzzz, rbba = xzzw, rbar = xzwx, rbag = xzwy, rbab = xzwz, rbaa = xzww,
		rarr = xwxx, rarg = xwxy, rarb = xwxz, rara = xwxw, ragr = xwyx, ragg = xwyy, ragb = xwyz, raga = xwyw,
		rabr = xwzx, rabg = xwzy, rabb = xwzz, raba = xwzw, raar = xwwx, raag = xwwy, raab = xwwz, raaa = xwww,

		grrr = yxxx, grrg = yxxy, grrb = yxxz, grra = yxxw, grgr = yxyx, grgg = yxyy, grgb = yxyz, grga = yxyw,
		grbr = yxzx, grbg = yxzy, grbb = yxzz, grba = yxzw, grar = yxwx, grag = yxwy, grab = yxwz, graa = yxww,
		ggrr = yyxx, ggrg = yyxy, ggrb = yyxz, ggra = yyxw, gggr = yyyx, gggg = yyyy, gggb = yyyz, ggga = yyyw,
		ggbr = yyzx, ggbg = yyzy, ggbb = yyzz, ggba = yyzw, ggar = yywx, ggag = yywy, ggab = yywz, ggaa = yyww,
		gbrr = yzxx, gbrg = yzxy, gbrb = yzxz, gbra = yzxw, gbgr = yzyx, gbgg = yzyy, gbgb = yzyz, gbga = yzyw,
		gbbr = yzzx, gbbg = yzzy, gbbb = yzzz, gbba = yzzw, gbar = yzwx, gbag = yzwy, gbab = yzwz, gbaa = yzww,
		garr = ywxx, garg = ywxy, garb = ywxz, gara = ywxw, gagr = ywyx, gagg = ywyy, gagb = ywyz, gaga = ywyw,
		gabr = ywzx, gabg = ywzy, gabb = ywzz, gaba = ywzw, gaar = ywwx, gaag = ywwy, gaab = ywwz, gaaa = ywww,

		brrr = zxxx, brrg = zxxy, brrb = zxxz, brra = zxxw, brgr = zxyx, brgg = zxyy, brgb = zxyz, brga = zxyw,
		brbr = zxzx, brbg = zxzy, brbb = zxzz, brba = zxzw, brar = zxwx, brag = zxwy, brab = zxwz, braa = zxww,
		bgrr = zyxx, bgrg = zyxy, bgrb = zyxz, bgra = zyxw, bggr = zyyx, bggg = zyyy, bggb = zyyz, bgga = zyyw,
		bgbr = zyzx, bgbg = zyzy, bgbb = zyzz, bgba = zyzw, bgar = zywx, bgag = zywy, bgab = zywz, bgaa = zyww,
		bbrr = zzxx, bbrg = zzxy, bbrb = zzxz, bbra = zzxw, bbgr = zzyx, bbgg = zzyy, bbgb = zzyz, bbga = zzyw,
		bbbr = zzzx, bbbg = zzzy, bbbb = zzzz, bbba = zzzw, bbar = zzwx, bbag = zzwy, bbab = zzwz, bbaa = zzww,
		barr = zwxx, barg = zwxy, barb = zwxz, bara = zwxw, bagr = zwyx, bagg = zwyy, bagb = zwyz, baga = zwyw,
		babr = zwzx, babg = zwzy, babb = zwzz, baba = zwzw, baar = zwwx, baag = zwwy, baab = zwwz, baaa = zwww,

		arrr = wxxx, arrg = wxxy, arrb = wxxz, arra = wxxw, argr = wxyx, argg = wxyy, argb = wxyz, arga = wxyw,
		arbr = wxzx, arbg = wxzy, arbb = wxzz, arba = wxzw, arar = wxwx, arag = wxwy, arab = wxwz, araa = wxww,
		agrr = wyxx, agrg = wyxy, agrb = wyxz, agra = wyxw, aggr = wyyx, aggg = wyyy, aggb = wyyz, agga = wyyw,
		agbr = wyzx, agbg = wyzy, agbb = wyzz, agba = wyzw, agar = wywx, agag = wywy, agab = wywz, agaa = wyww,
		abrr = wzxx, abrg = wzxy, abrb = wzxz, abra = wzxw, abgr = wzyx, abgg = wzyy, abgb = wzyz, abga = wzyw,
		abbr = wzzx, abbg = wzzy, abbb = wzzz, abba = wzzw, abar = wzwx, abag = wzwy, abab = wzwz, abaa = wzww,
		aarr = wwxx, aarg = wwxy, aarb = wwxz, aara = wwxw, aagr = wwyx, aagg = wwyy, aagb = wwyz, aaga = wwyw,
		aabr = wwzx, aabg = wwzy, aabb = wwzz, aaba = wwzw, aaar = wwwx, aaag = wwwy, aaab = wwwz, aaaa = wwww,

	};

	inline std::string SwizzleExtension(Swizzle swizzle)
	{
		switch (swizzle)
		{
		case Swizzle::x:
			return "x";
		case Swizzle::y:
			return "y";
		case Swizzle::z:
			return "z";
		case Swizzle::w:
			return "w";
		case Swizzle::xx:
			return "xx";
		case Swizzle::xy:
			return "xy";
		case Swizzle::xz:
			return "xz";
		case Swizzle::xw:
			return "xw";
		case Swizzle::yx:
			return "yx";
		case Swizzle::yy:
			return "yy";
		case Swizzle::yz:
			return "yz";
		case Swizzle::yw:
			return "yw";
		case Swizzle::zx:
			return "zx";
		case Swizzle::zy:
			return "zy";
		case Swizzle::zz:
			return "zz";
		case Swizzle::zw:
			return "zw";
		case Swizzle::wx:
			return "wx";
		case Swizzle::wy:
			return "wy";
		case Swizzle::wz:
			return "wz";
		case Swizzle::ww:
			return "ww";
		case Swizzle::xxx:
			return "xxx";
		case Swizzle::xxy:
			return "xxy";
		case Swizzle::xxz:
			return "xxz";
		case Swizzle::xxw:
			return "xxw";
		case Swizzle::xyx:
			return "xyx";
		case Swizzle::xyy:
			return "xyy";
		case Swizzle::xyz:
			return "xyz";
		case Swizzle::xyw:
			return "xyw";
		case Swizzle::xzx:
			return "xzx";
		case Swizzle::xzy:
			return "xzy";
		case Swizzle::xzz:
			return "xzz";
		case Swizzle::xzw:
			return "xzw";
		case Swizzle::xwx:
			return "xwx";
		case Swizzle::xwy:
			return "xwy";
		case Swizzle::xwz:
			return "xwz";
		case Swizzle::xww:
			return "xww";
		case Swizzle::yxx:
			return "yxx";
		case Swizzle::yxy:
			return "yxy";
		case Swizzle::yxz:
			return "yxz";
		case Swizzle::yxw:
			return "yxw";
		case Swizzle::yyx:
			return "yyx";
		case Swizzle::yyy:
			return "yyy";
		case Swizzle::yyz:
			return "yyz";
		case Swizzle::yyw:
			return "yyw";
		case Swizzle::yzx:
			return "yzx";
		case Swizzle::yzy:
			return "yzy";
		case Swizzle::yzz:
			return "yzz";
		case Swizzle::yzw:
			return "yzw";
		case Swizzle::ywx:
			return "ywx";
		case Swizzle::ywy:
			return "ywy";
		case Swizzle::ywz:
			return "ywz";
		case Swizzle::yww:
			return "yww";
		case Swizzle::zxx:
			return "zxx";
		case Swizzle::zxy:
			return "zxy";
		case Swizzle::zxz:
			return "zxz";
		case Swizzle::zxw:
			return "zxw";
		case Swizzle::zyx:
			return "zyx";
		case Swizzle::zyy:
			return "zyy";
		case Swizzle::zyz:
			return "zyz";
		case Swizzle::zyw:
			return "zyw";
		case Swizzle::zzx:
			return "zzx";
		case Swizzle::zzy:
			return "zzy";
		case Swizzle::zzz:
			return "zzz";
		case Swizzle::zzw:
			return "zzw";
		case Swizzle::zwx:
			return "zwx";
		case Swizzle::zwy:
			return "zwy";
		case Swizzle::zwz:
			return "zwz";
		case Swizzle::zww:
			return "zww";
		case Swizzle::wxx:
			return "wxx";
		case Swizzle::wxy:
			return "wxy";
		case Swizzle::wxz:
			return "wxz";
		case Swizzle::wxw:
			return "wxw";
		case Swizzle::wyx:
			return "wyx";
		case Swizzle::wyy:
			return "wyy";
		case Swizzle::wyz:
			return "wyz";
		case Swizzle::wyw:
			return "wyw";
		case Swizzle::wzx:
			return "wzx";
		case Swizzle::wzy:
			return "wzy";
		case Swizzle::wzz:
			return "wzz";
		case Swizzle::wzw:
			return "wzw";
		case Swizzle::wwx:
			return "wwx";
		case Swizzle::wwy:
			return "wwy";
		case Swizzle::wwz:
			return "wwz";
		case Swizzle::www:
			return "www";
		case Swizzle::xxxx:
			return "xxxx";
		case Swizzle::xxxy:
			return "xxxy";
		case Swizzle::xxxz:
			return "xxxz";
		case Swizzle::xxxw:
			return "xxxw";
		case Swizzle::xxyx:
			return "xxyx";
		case Swizzle::xxyy:
			return "xxyy";
		case Swizzle::xxyz:
			return "xxyz";
		case Swizzle::xxyw:
			return "xxyw";
		case Swizzle::xxzx:
			return "xxzx";
		case Swizzle::xxzy:
			return "xxzy";
		case Swizzle::xxzz:
			return "xxzz";
		case Swizzle::xxzw:
			return "xxzw";
		case Swizzle::xxwx:
			return "xxwx";
		case Swizzle::xxwy:
			return "xxwy";
		case Swizzle::xxwz:
			return "xxwz";
		case Swizzle::xxww:
			return "xxww";
		case Swizzle::xyxx:
			return "xyxx";
		case Swizzle::xyxy:
			return "xyxy";
		case Swizzle::xyxz:
			return "xyxz";
		case Swizzle::xyxw:
			return "xyxw";
		case Swizzle::xyyx:
			return "xyyx";
		case Swizzle::xyyy:
			return "xyyy";
		case Swizzle::xyyz:
			return "xyyz";
		case Swizzle::xyyw:
			return "xyyw";
		case Swizzle::xyzx:
			return "xyzx";
		case Swizzle::xyzy:
			return "xyzy";
		case Swizzle::xyzz:
			return "xyzz";
		case Swizzle::xyzw:
			return "xyzw";
		case Swizzle::xywx:
			return "xywx";
		case Swizzle::xywy:
			return "xywy";
		case Swizzle::xywz:
			return "xywz";
		case Swizzle::xyww:
			return "xyww";
		case Swizzle::xzxx:
			return "xzxx";
		case Swizzle::xzxy:
			return "xzxy";
		case Swizzle::xzxz:
			return "xzxz";
		case Swizzle::xzxw:
			return "xzxw";
		case Swizzle::xzyx:
			return "xzyx";
		case Swizzle::xzyy:
			return "xzyy";
		case Swizzle::xzyz:
			return "xzyz";
		case Swizzle::xzyw:
			return "xzyw";
		case Swizzle::xzzx:
			return "xzzx";
		case Swizzle::xzzy:
			return "xzzy";
		case Swizzle::xzzz:
			return "xzzz";
		case Swizzle::xzzw:
			return "xzzw";
		case Swizzle::xzwx:
			return "xzwx";
		case Swizzle::xzwy:
			return "xzwy";
		case Swizzle::xzwz:
			return "xzwz";
		case Swizzle::xzww:
			return "xzww";
		case Swizzle::xwxx:
			return "xwxx";
		case Swizzle::xwxy:
			return "xwxy";
		case Swizzle::xwxz:
			return "xwxz";
		case Swizzle::xwxw:
			return "xwxw";
		case Swizzle::xwyx:
			return "xwyx";
		case Swizzle::xwyy:
			return "xwyy";
		case Swizzle::xwyz:
			return "xwyz";
		case Swizzle::xwyw:
			return "xwyw";
		case Swizzle::xwzx:
			return "xwzx";
		case Swizzle::xwzy:
			return "xwzy";
		case Swizzle::xwzz:
			return "xwzz";
		case Swizzle::xwzw:
			return "xwzw";
		case Swizzle::xwwx:
			return "xwwx";
		case Swizzle::xwwy:
			return "xwwy";
		case Swizzle::xwwz:
			return "xwwz";
		case Swizzle::xwww:
			return "xwww";
		case Swizzle::yxxx:
			return "yxxx";
		case Swizzle::yxxy:
			return "yxxy";
		case Swizzle::yxxz:
			return "yxxz";
		case Swizzle::yxxw:
			return "yxxw";
		case Swizzle::yxyx:
			return "yxyx";
		case Swizzle::yxyy:
			return "yxyy";
		case Swizzle::yxyz:
			return "yxyz";
		case Swizzle::yxyw:
			return "yxyw";
		case Swizzle::yxzx:
			return "yxzx";
		case Swizzle::yxzy:
			return "yxzy";
		case Swizzle::yxzz:
			return "yxzz";
		case Swizzle::yxzw:
			return "yxzw";
		case Swizzle::yxwx:
			return "yxwx";
		case Swizzle::yxwy:
			return "yxwy";
		case Swizzle::yxwz:
			return "yxwz";
		case Swizzle::yxww:
			return "yxww";
		case Swizzle::yyxx:
			return "yyxx";
		case Swizzle::yyxy:
			return "yyxy";
		case Swizzle::yyxz:
			return "yyxz";
		case Swizzle::yyxw:
			return "yyxw";
		case Swizzle::yyyx:
			return "yyyx";
		case Swizzle::yyyy:
			return "yyyy";
		case Swizzle::yyyz:
			return "yyyz";
		case Swizzle::yyyw:
			return "yyyw";
		case Swizzle::yyzx:
			return "yyzx";
		case Swizzle::yyzy:
			return "yyzy";
		case Swizzle::yyzz:
			return "yyzz";
		case Swizzle::yyzw:
			return "yyzw";
		case Swizzle::yywx:
			return "yywx";
		case Swizzle::yywy:
			return "yywy";
		case Swizzle::yywz:
			return "yywz";
		case Swizzle::yyww:
			return "yyww";
		case Swizzle::yzxx:
			return "yzxx";
		case Swizzle::yzxy:
			return "yzxy";
		case Swizzle::yzxz:
			return "yzxz";
		case Swizzle::yzxw:
			return "yzxw";
		case Swizzle::yzyx:
			return "yzyx";
		case Swizzle::yzyy:
			return "yzyy";
		case Swizzle::yzyz:
			return "yzyz";
		case Swizzle::yzyw:
			return "yzyw";
		case Swizzle::yzzx:
			return "yzzx";
		case Swizzle::yzzy:
			return "yzzy";
		case Swizzle::yzzz:
			return "yzzz";
		case Swizzle::yzzw:
			return "yzzw";
		case Swizzle::yzwx:
			return "yzwx";
		case Swizzle::yzwy:
			return "yzwy";
		case Swizzle::yzwz:
			return "yzwz";
		case Swizzle::yzww:
			return "yzww";
		case Swizzle::ywxx:
			return "ywxx";
		case Swizzle::ywxy:
			return "ywxy";
		case Swizzle::ywxz:
			return "ywxz";
		case Swizzle::ywxw:
			return "ywxw";
		case Swizzle::ywyx:
			return "ywyx";
		case Swizzle::ywyy:
			return "ywyy";
		case Swizzle::ywyz:
			return "ywyz";
		case Swizzle::ywyw:
			return "ywyw";
		case Swizzle::ywzx:
			return "ywzx";
		case Swizzle::ywzy:
			return "ywzy";
		case Swizzle::ywzz:
			return "ywzz";
		case Swizzle::ywzw:
			return "ywzw";
		case Swizzle::ywwx:
			return "ywwx";
		case Swizzle::ywwy:
			return "ywwy";
		case Swizzle::ywwz:
			return "ywwz";
		case Swizzle::ywww:
			return "ywww";
		case Swizzle::zxxx:
			return "zxxx";
		case Swizzle::zxxy:
			return "zxxy";
		case Swizzle::zxxz:
			return "zxxz";
		case Swizzle::zxxw:
			return "zxxw";
		case Swizzle::zxyx:
			return "zxyx";
		case Swizzle::zxyy:
			return "zxyy";
		case Swizzle::zxyz:
			return "zxyz";
		case Swizzle::zxyw:
			return "zxyw";
		case Swizzle::zxzx:
			return "zxzx";
		case Swizzle::zxzy:
			return "zxzy";
		case Swizzle::zxzz:
			return "zxzz";
		case Swizzle::zxzw:
			return "zxzw";
		case Swizzle::zxwx:
			return "zxwx";
		case Swizzle::zxwy:
			return "zxwy";
		case Swizzle::zxwz:
			return "zxwz";
		case Swizzle::zxww:
			return "zxww";
		case Swizzle::zyxx:
			return "zyxx";
		case Swizzle::zyxy:
			return "zyxy";
		case Swizzle::zyxz:
			return "zyxz";
		case Swizzle::zyxw:
			return "zyxw";
		case Swizzle::zyyx:
			return "zyyx";
		case Swizzle::zyyy:
			return "zyyy";
		case Swizzle::zyyz:
			return "zyyz";
		case Swizzle::zyyw:
			return "zyyw";
		case Swizzle::zyzx:
			return "zyzx";
		case Swizzle::zyzy:
			return "zyzy";
		case Swizzle::zyzz:
			return "zyzz";
		case Swizzle::zyzw:
			return "zyzw";
		case Swizzle::zywx:
			return "zywx";
		case Swizzle::zywy:
			return "zywy";
		case Swizzle::zywz:
			return "zywz";
		case Swizzle::zyww:
			return "zyww";
		case Swizzle::zzxx:
			return "zzxx";
		case Swizzle::zzxy:
			return "zzxy";
		case Swizzle::zzxz:
			return "zzxz";
		case Swizzle::zzxw:
			return "zzxw";
		case Swizzle::zzyx:
			return "zzyx";
		case Swizzle::zzyy:
			return "zzyy";
		case Swizzle::zzyz:
			return "zzyz";
		case Swizzle::zzyw:
			return "zzyw";
		case Swizzle::zzzx:
			return "zzzx";
		case Swizzle::zzzy:
			return "zzzy";
		case Swizzle::zzzz:
			return "zzzz";
		case Swizzle::zzzw:
			return "zzzw";
		case Swizzle::zzwx:
			return "zzwx";
		case Swizzle::zzwy:
			return "zzwy";
		case Swizzle::zzwz:
			return "zzwz";
		case Swizzle::zzww:
			return "zzww";
		case Swizzle::zwxx:
			return "zwxx";
		case Swizzle::zwxy:
			return "zwxy";
		case Swizzle::zwxz:
			return "zwxz";
		case Swizzle::zwxw:
			return "zwxw";
		case Swizzle::zwyx:
			return "zwyx";
		case Swizzle::zwyy:
			return "zwyy";
		case Swizzle::zwyz:
			return "zwyz";
		case Swizzle::zwyw:
			return "zwyw";
		case Swizzle::zwzx:
			return "zwzx";
		case Swizzle::zwzy:
			return "zwzy";
		case Swizzle::zwzz:
			return "zwzz";
		case Swizzle::zwzw:
			return "zwzw";
		case Swizzle::zwwx:
			return "zwwx";
		case Swizzle::zwwy:
			return "zwwy";
		case Swizzle::zwwz:
			return "zwwz";
		case Swizzle::zwww:
			return "zwww";
		case Swizzle::wxxx:
			return "wxxx";
		case Swizzle::wxxy:
			return "wxxy";
		case Swizzle::wxxz:
			return "wxxz";
		case Swizzle::wxxw:
			return "wxxw";
		case Swizzle::wxyx:
			return "wxyx";
		case Swizzle::wxyy:
			return "wxyy";
		case Swizzle::wxyz:
			return "wxyz";
		case Swizzle::wxyw:
			return "wxyw";
		case Swizzle::wxzx:
			return "wxzx";
		case Swizzle::wxzy:
			return "wxzy";
		case Swizzle::wxzz:
			return "wxzz";
		case Swizzle::wxzw:
			return "wxzw";
		case Swizzle::wxwx:
			return "wxwx";
		case Swizzle::wxwy:
			return "wxwy";
		case Swizzle::wxwz:
			return "wxwz";
		case Swizzle::wxww:
			return "wxww";
		case Swizzle::wyxx:
			return "wyxx";
		case Swizzle::wyxy:
			return "wyxy";
		case Swizzle::wyxz:
			return "wyxz";
		case Swizzle::wyxw:
			return "wyxw";
		case Swizzle::wyyx:
			return "wyyx";
		case Swizzle::wyyy:
			return "wyyy";
		case Swizzle::wyyz:
			return "wyyz";
		case Swizzle::wyyw:
			return "wyyw";
		case Swizzle::wyzx:
			return "wyzx";
		case Swizzle::wyzy:
			return "wyzy";
		case Swizzle::wyzz:
			return "wyzz";
		case Swizzle::wyzw:
			return "wyzw";
		case Swizzle::wywx:
			return "wywx";
		case Swizzle::wywy:
			return "wywy";
		case Swizzle::wywz:
			return "wywz";
		case Swizzle::wyww:
			return "wyww";
		case Swizzle::wzxx:
			return "wzxx";
		case Swizzle::wzxy:
			return "wzxy";
		case Swizzle::wzxz:
			return "wzxz";
		case Swizzle::wzxw:
			return "wzxw";
		case Swizzle::wzyx:
			return "wzyx";
		case Swizzle::wzyy:
			return "wzyy";
		case Swizzle::wzyz:
			return "wzyz";
		case Swizzle::wzyw:
			return "wzyw";
		case Swizzle::wzzx:
			return "wzzx";
		case Swizzle::wzzy:
			return "wzzy";
		case Swizzle::wzzz:
			return "wzzz";
		case Swizzle::wzzw:
			return "wzzw";
		case Swizzle::wzwx:
			return "wzwx";
		case Swizzle::wzwy:
			return "wzwy";
		case Swizzle::wzwz:
			return "wzwz";
		case Swizzle::wzww:
			return "wzww";
		case Swizzle::wwxx:
			return "wwxx";
		case Swizzle::wwxy:
			return "wwxy";
		case Swizzle::wwxz:
			return "wwxz";
		case Swizzle::wwxw:
			return "wwxw";
		case Swizzle::wwyx:
			return "wwyx";
		case Swizzle::wwyy:
			return "wwyy";
		case Swizzle::wwyz:
			return "wwyz";
		case Swizzle::wwyw:
			return "wwyw";
		case Swizzle::wwzx:
			return "wwzx";
		case Swizzle::wwzy:
			return "wwzy";
		case Swizzle::wwzz:
			return "wwzz";
		case Swizzle::wwzw:
			return "wwzw";
		case Swizzle::wwwx:
			return "wwwx";
		case Swizzle::wwwy:
			return "wwwy";
		case Swizzle::wwwz:
			return "wwwz";
		case Swizzle::wwww:
			return "wwww";
		default:
			break;
		}

		return "BAD_SWIZZLE";
	}

}

#endif
