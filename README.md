# Quiz12
> 第20組
> 
組員:
  1. B11115001 - 譚秉家
  2. B11130237 - 廖廷安
---
# 編譯說明
因為繳交要求而把.cpp與.h直接放在submit資料夾內

實際編譯時需要依照下列檔案分配
* /src
  * *.cpp
* /include
  * *.h
* CMakeLists.txt
  
## 題目說明
* 建立Item Class並在底下繼承帶不同特性的不同Item (0.3%)
  * (Item定義為非Hero及Creature之其他Object，例如Trigger)
> 建立Item class，並且把Trigger重新設計成為繼承Item class的物件
>
> 實作行數: 48 (Item.h) 117(Item.cpp)
* 實作除了Trigger以外至少一種以上的Item (0.2%)
> 建立HeartCrystal物件，Hero碰到時會增加20 MaxHP與回覆6點HP
>
> 實作行數: 28(HeartCrystal.h) 66(HeartCrystal.cpp)
* 實作Item Class的多型行為 (0.3%)
> 在Item.h中定義 virtual void update(Hero& hero)，而HeartCrystal.h、Trigger.h中定義 void update(Hero& hero) override
>
> 實作行數: 3(Item.h、Trigger.h、HeartCrystal.h)
* 統一使用Item*陣列/Vector管理 (0.2%)
> 在Start.cpp中定義vector<Item*> gItems; 統一管理Item物件
>
> 實作行數: 12(Start.cpp)

