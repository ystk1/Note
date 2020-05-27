# PyInstallの使用

## python をexe形式に

---
## 環境構築
---
```
pip install pyinstaller
```



---
## exe化手順
---
```
pyinstaller pythonファイル名 [--onefile] [--noconsole]

–onefile は関連するファイルを1つにまとめてexeファイルを作成
–noconsole はコンソール（コマンドプロンプト）の黒い画面を表示しない
```

例：pyinstaller hello.py --onefile  
実行後、distフォルダにexeができる。

---



