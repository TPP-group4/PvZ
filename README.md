# PvZ

## 遊戲流程
1. 玩家移動先
   1. 空的地: 要不要種植物
   2. 有植物: 看植物是啥(Coin, Horn, Bomb, Heal)
2. 殭屍移動
   1. 空的地: nothing happens
   2. 有植物: 攻擊性植物(Horn, Bomb)先攻擊, 若殭屍與植物都存活, 換殭屍攻擊
3. 遊戲結束
   1. 玩家殺死所有殭屍, 且還有植物存活(Bomb的數量不多於一半)
   2. 若所有植物死光, 玩家lose

## class 設計
- 植物 (Plant.h)
  - Horn
  - Bomb
  - Coin
  - Heal