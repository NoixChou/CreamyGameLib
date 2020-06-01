# CreamyGameLib
きっとUnity/UnrealEngine感があるようで無いSDL or DxLibで動くゲーム~~エンジン~~ライブラリ  
有名な黒いC++ゲームプログラミング本を大いに参考にしています  

## 注意
VS2019 & VC++しか考えてないのでこれでしか動かないと思います...  
ソースコード自体は(DxLib部を除けば)環境依存してない？(未確認)

## 使い方
`CreamyGameLib`プロジェクトをビルドすると`CreamyGameLib/lib`の中にライブラリができます。  
`CreamyGameLib.lib`はSDL版、`CreamyGameLib_DxLib.lib`がDxLib版。  
どっち使っても見た目は変わらないはずです。  
ソリューション構成の名前が`-DxLib`付きであればDxLib版が、付いてない方ならSDL版が生成されます。  
  
`TestGame`プロジェクトにはちょこちょこっと動くコードを書いてあります。  
スタートアッププロジェクトになってるので、F5キーを押せば考えることなしに動くはずです。  
  
`InternalLib`はSDL/DxLibの抽象化ライブラリです。  
マクロ`CREAMY_USE_DXLIB`が定義されているとDxLib版が、`CREAMY_USE_SDL`が定義されているとSDL版が生成されます。  
どっちも定義されていなかったらSDL版が生成されます。

## ライセンス表記
### SDL
[External/SDL](https://github.com/NoixChou/CreamyGameLib/tree/master/External/SDL)  

### DxLib
DX Library Copyright (C) 2001-2020 Takumi Yamada.

libjpeg　Copyright (C) 1991-2013, Thomas G. Lane, Guido Vollbeding.  
this software is based in part on the work of the Independent JPEG Group  
  
  
libpng　Copyright (C) 2004, 2006-2012 Glenn Randers-Pehrson.  
zlib　Copyright (C) 1995-2012 Jean-loup Gailly and Mark Adler.  
  
  
libtiff　Copyright (c) 1988-1997 Sam Leffler  
libtiff　Copyright (c) 1991-1997 Silicon Graphics, Inc.  
  
Permission to use, copy, modify, distribute, and sell this software and  
its documentation for any purpose is hereby granted without fee, provided  
that (i) the above copyright notices and this permission notice appear in  
all copies of the software and related documentation, and (ii) the names of  
Sam Leffler and Silicon Graphics may not be used in any advertising or  
publicity relating to the software without the specific, prior written  
permission of Sam Leffler and Silicon Graphics.  
  
THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,  
EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY  
WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  
  
IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  
ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  
OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  
WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF  
LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE  
OF THIS SOFTWARE.  
  
  
libogg　Copyright (C) 2002-2009 Xiph.org Foundation  
  
Redistribution and use in source and binary forms, with or without  
modification, are permitted provided that the following conditions  
are met:  
  
\- Redistributions of source code must retain the above copyright  
notice, this list of conditions and the following disclaimer.  
  
\- Redistributions in binary form must reproduce the above copyright  
notice, this list of conditions and the following disclaimer in the  
documentation and/or other materials provided with the distribution.  
  
\- Neither the name of the Xiph.org Foundation nor the names of its  
contributors may be used to endorse or promote products derived from  
this software without specific prior written permission.  
  
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE FOUNDATION  
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
  
Opus audio codec  
Copyright 2001-2011 Xiph.Org, Skype Limited, Octasic,  
Jean-Marc Valin, Timothy B. Terriberry,  
CSIRO, Gregory Maxwell, Mark Borgerding,  
Erik de Castro Lopo  
  
Redistribution and use in source and binary forms, with or without  
modification, are permitted provided that the following conditions  
are met:  
  
\- Redistributions of source code must retain the above copyright  
notice, this list of conditions and the following disclaimer.  
  
\- Redistributions in binary form must reproduce the above copyright  
notice, this list of conditions and the following disclaimer in the  
documentation and/or other materials provided with the distribution.  
  
\- Neither the name of Internet Society, IETF or IETF Trust, nor the  
names of specific contributors, may be used to endorse or promote  
products derived from this software without specific prior written  
permission.  
  
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER  
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
  
Opusfile  
Copyright (c) 1994-2013 Xiph.Org Foundation and contributors  
  
Redistribution and use in source and binary forms, with or without  
modification, are permitted provided that the following conditions  
are met:  
  
\- Redistributions of source code must retain the above copyright  
notice, this list of conditions and the following disclaimer.  
  
\- Redistributions in binary form must reproduce the above copyright  
notice, this list of conditions and the following disclaimer in the  
documentation and/or other materials provided with the distribution.  
  
\- Neither the name of the Xiph.Org Foundation nor the names of its  
contributors may be used to endorse or promote products derived from  
this software without specific prior written permission.  
  
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE FOUNDATION  
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
  
Mersenne Twister  
Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,  
All rights reserved.  
  
Redistribution and use in source and binary forms, with or without  
modification, are permitted provided that the following conditions  
are met:  
  
1. Redistributions of source code must retain the above copyright  
notice, this list of conditions and the following disclaimer.  
  
2. Redistributions in binary form must reproduce the above copyright  
notice, this list of conditions and the following disclaimer in the  
documentation and/or other materials provided with the distribution.  
  
3. The name of the author may not be used to endorse or promote products  
derived from this software without specific prior written permission.  
  
THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
  
Bullet　Copyright (c) 2003-2006 Erwin Coumans.
