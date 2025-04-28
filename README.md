# MultiDisconnected
## 概要
UnrealEngineでプレイヤーが接続を切断したときにどうなるかの検証用プロジェクトです。

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