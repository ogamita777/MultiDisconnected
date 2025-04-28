# MultiDisconnected
## 概要
UnrealEngineでプレイヤーが接続を切断したときの挙動を検証するためのプロジェクトです。

[【UE5】マルチプレイにおいてプレイヤーが接続を切断したときの挙動 #UnrealEngine - Qiita](https://qiita.com/ogamita777/items/3f844f365d103c8b783b) に検証内容を投稿いたしております。

## 環境
- UnrealEngine 5.5.4

## 操作方法
- 移動：WASD
- カメラ操作：マウス

## ツール
Toolフォルダに各種ツールが格納されています。

### Editor/MakePackage.bat
Developtmentの構成でパッケージ作成します。  
MultiDisconnected\Saved\StagedBuilds\Windows にパッケージは配置されます。  
デフォルトパスの C:\Program Files\Epic Games\UE_5.5 にUnrealEngine5.5が格納されている場合に動作します。

### Editor/Launch_Stage_ListenServer.bat
パッケージをListenServerで起動します。

### Editor/Launch_Stage_Client.bat
パッケージをClient(127.0.0.1に繋ぐ)で起動します。