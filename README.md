
<details>
  <summary> 
    
### 装备武器
  </summary>

  <details>
    <summary>在装备武器时，montage没有播放结束，重复按键，技能会重新触发，可以选择以下一种方式解决</summary>
    
> - 可以在代码中检测AbiltySpec是否为Active状态，如果是Active，则不触发技能
> - 技能蓝图中修改Instancing Policy为Instanced Per Actor
> - 技能蓝图中设置Block ABilities With Tag，block掉其他技能

  </details>

  <details>
    <summary>技能触发完按住按键才能触发</summary>

> 主要还是因为松开按键时，触发了OnAbilityInputReleased中的CancelAbilityHandle函数，所以要检测tag，提前return
  </details>

</details>
