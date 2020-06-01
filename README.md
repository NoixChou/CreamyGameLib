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
