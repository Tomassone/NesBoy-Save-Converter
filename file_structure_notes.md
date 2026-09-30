# Pokémon Yellow NES Port — Save File / RAM Structure Notes

Notes for the Shenzhen Nanjing Technology Co., Ltd. NES port.

## 1. Main Save / RAM Map

| Address / range | Description | Notes |
|---|---:|---|
| `0x0023-0x0025` | Player money | |
| `0x0030` | Number of Pokémon in party | |
| `0x0031` | Pokédex - Trainer screen [Pokémon seen] | |
| `0x0032` | Pokédex - Trainer screen [Pokémon caught] | |
| `0x0033` | Species of first Pokémon | |
| `0x0033-0x0038` | Party Pokémon species | |
| `0x0039` | Level of first Pokémon | |
| `0x0039-0x003E` | Party Pokémon levels | |
| `0x003F` | Current HP of first Pokémon | |
| `0x003F-0x0044` | Party Pokémon current HP | |
| `0x004B-0x0050` | Party Pokémon max HP | |
| `0x0057` | Experience needed for next level | |
| `0x0057-0x005C` | Party Pokémon experience points | |
| `0x0063` | First move of first Pokémon | With `FF`, I clear it |
| `0x0063-0x0068` | Party Pokémon first moves | |
| `0x0069` | Second move of first Pokémon | |
| `0x0069-0x006E` | Party Pokémon second moves | |
| `0x006F` | Third move of first Pokémon | |
| `0x006F-0x0074` | Party Pokémon third moves | |
| `0x0075` | Fourth move of first Pokémon | |
| `0x0075-0x007A` | Party Pokémon fourth moves | |
| `0x007B-0x0080` | Party Pokémon PP: first move | |
| `0x0081-0x0086` | Party Pokémon PP: second move | |
| `0x0087-0x008C` | Party Pokémon PP: third move | |
| `0x008D-0x0092` | Party Pokémon PP: fourth move | |
| `0x009F` | Pokémon caught - Pokédex | |
| `0x00B3` | Pokémon seen - Pokédex | |
| `0x00C7` | Player badges | |
| `0x00C9-0x00CE` | Party Pokémon order | |
| `0x00D0-0x00D3` | Various Poké Ball types | |
| `0x00D4-0x00DF` and `0x00E0-0x00E6` | Consumable items | |
| `0x00E7-0x00EF` and `0x00F0-0x00F1` | Basic items | |
| `0x00F2-0x00F6` | HMs | |
| `0x00F2-0x00FF`, `0x0102-0x010F`, `0x0112-0x011E` | TMs and HMs | |
| `0x011F` | Number of Pokémon in box | |
| `0x0120` | Species of first Pokémon in box | |
| `0x0121` | Level of first Pokémon in box | |
| `0x0122` | Experience points of first Pokémon in box | |
| `0x0124-0x0127` | Moves of first Pokémon in box | |

> From `0x0C00:00`, data repeats. Changing it does nothing while the game is running.

### Opponent data

| Address / range | Description |
|---|---|
| `0x1D46` | Opponent Pokémon species |
| `0x1D47` | Opponent Pokémon level |
| `0x1D48-0x1D4B` | Opponent Pokémon HP |

---

## 2. Item RAM Addresses

Incomplete list of items with their RAM addresses:

| Address | Item |
|---:|---|
| `0x60D0` | Poké Ball |
| `0x60D1` | Great Ball |
| `0x60D2` | Ultra Ball |
| `0x60D3` | Master Ball |
| `0x60D4` | Potion |
| `0x60D5` | Super Potion |
| `0x60D6` | Hyper Potion |
| `0x60D7` | Max Potion |
| `0x60D8` | Antidote |
| `0x60D9` | Parlyz Heal |
| `0x60DA` | Awakening |
| `0x60DB` | Ice Heal |
| `0x60DC` | Burn Heal |
| `0x60DD` | Full Heal |
| `0x60DE` | Revive |
| `0x60DF` | Ether |
| `0x60E0` | Max Ether |
| `0x60E1` | Rare Candy |
| `0x60E2` | Fire Stone |
| `0x60E3` | Water Stone |
| `0x60E4` | ThunderStone |
| `0x60E5` | Leaf Stone |
| `0x60E6` | Moon Stone |
| `0x60E7` | Oak's Parcel |
| `0x60E8` | Pokédex |
| `0x60E9` | Map |
| `0x60EA` | Helix Fossil |
| `0x60EB` | Dome Fossil |
| `0x60EC` | SS Ticket |
| `0x60ED` | Hot Tea? |
| `0x60EE` | Silph Scope |
| `0x60EF` | Poké Flute |
| `0x60F0` | Gold Teeth |
| `0x60F1` | Secret Key |
| `0x60F2` | HM01 Cut |
| `0x60F3` | HM02 Fly |
| `0x60F4` | HM03 Surf |
| `0x60F5` | HM04 Strength |
| `0x60F6` | HM05 Flash |
| `0x60F7` | TM01 Focus Punch |
| `0x60F8` | TM02 Dragon Claw |
| `0x60F9` | TM03 Water Pulse |
| `0x60FA` | TM04 Calm Mind |
| `0x60FB` | TM05 Roar |
| `0x60FC` | TM06 Toxic |
| `0x60FD` | TM07 Hidden Power |
| `0x60FE` | TM08 Bulk Up |
| `0x60FF` | TM09 Rest |
| `0x6100` | TM10 |
| `0x6101` | TM11 BubbleBeam |
| `0x6102` | TM12 Steel Wing |
| `0x6103` | TM13 Ice Beam |
| `0x6104` | TM14 Blizzard |
| `0x6105` | TM15 Hyper Beam |
| `0x6106` | TM16 Sleep Talk? |
| `0x6107` | TM17 |
| `0x6108` | TM18 AncientPower |
| `0x6109` | TM19 |
| `0x610A` | TM20 |
| `0x610B` | TM21 |
| `0x610C` | TM22 SolarBeam |
| `0x610D` | TM23 Iron Tail |
| `0x610E` | TM24 Thunderbolt |
| `0x610F` | TM25 Thunder |
| `0x6110` | TM26 Earthquake |
| `0x6111` | TM27 Fissure |
| `0x6112` | TM28 Dig |
| `0x6113` | TM29 Psychic |
| `0x6114` | TM30 Shadow Ball |
| `0x6115` | TM31 |
| `0x6116` | TM32 |
| `0x6117` | TM33 |
| `0x6118` | TM34 Shock Wave |
| `0x6119` | TM35 |
| `0x611A` | TM36 Sludge Bomb |
| `0x611B` | TM37 Aerial Ace |
| `0x611C` | TM38 Fire Blast |
| `0x611D` | TM39 Rock Tomb |
| `0x611E` | TM40 Psywave |

---

## 3. Move List by Type

These names are in order of appearance in the ROM.  
Most attacks are from Generations 1, 2, and 3; only a few are from Gen 4.  
The IDs below are inferred from the type ranges and explicit hex notes in the source.

### Fire Type `00-07`

| Hex | Move |
|---:|---|
| `00` | Ember |
| `01` | Flame Wheel |
| `02` | Fire Punch |
| `03` | Flame Thrower |
| `04` | Sacred Fire |
| `05` | Fire Blast |
| `06` | Eruption |
| `07` | Will-O-Wisp |

### Water Type `08-12`

| Hex | Move |
|---:|---|
| `08` | Bubble |
| `09` | Water Gun |
| `0A` | Water Pulse |
| `0B` | Bubble Beam |
| `0C` | Octazooka |
| `0D` | Crab Hammer |
| `0E` | Surf |
| `0F` | Hydro Pump |
| `10` | Water Sprout |
| `11` | Clamp |
| `12` | Withdraw |

### Electric Type `13-1B`

| Hex | Move |
|---:|---|
| `13` | Thunder Shock |
| `14` | Shock Wave |
| `15` | Spark |
| `16` | Thunder Punch |
| `17` | Thunder Bolt |
| `18` | Zap Cannon |
| `19` | Volt Tackle |
| `1A` | Thunder |
| `1B` | Thunder Wave |

### Grass Type `1C-28`

| Hex | Move |
|---:|---|
| `1C` | Absorb |
| `1D` | Mega Drain |
| `1E` | Magic Leaf |
| `1F` | Vine Whip |
| `20` | Razor Leaf |
| `21` | Needle Arm |
| `22` | Seed Bomb |
| `23` | Solar Beam |
| `24` | Frenzy Plant |
| `25` | Grass Whistle |
| `26` | Sleep Powder |
| `27` | Spore |
| `28` | Stun Spore |

> The PP amount for some of these needs to be fixed.

### Ice Type `29-2F`

| Hex | Move |
|---:|---|
| `29` | Powder Snow |
| `2A` | Icy Wind |
| `2B` | Aurora Beam |
| `2C` | Ice Punch |
| `2D` | Ice Beam |
| `2E` | Blizzard |
| `2F` | Sheer Cold |

### Ground Type `30-37`

| Hex | Move |
|---:|---|
| `30` | Mud Slap |
| `31` | Mud Shot |
| `32` | Dig |
| `33` | Bone Club |
| `34` | Earth Quake |
| `35` | Bonemerang |
| `36` | Fissure |
| `37` | Sand Attack |

### Rock Type `38-3B`

| Hex | Move |
|---:|---|
| `38` | Rock Throw |
| `39` | Rock Tomb |
| `3A` | Ancient Power |
| `3B` | Rock Slide |

### Bug Type `3C-42`

| Hex | Move |
|---:|---|
| `3C` | Leech Life |
| `3D` | Twin Needle |
| `3E` | Silver Wind |
| `3F` | Signal Beam |
| `40` | Mega Horn |
| `41` | Tail Grow |
| `42` | String Shot |

### Poison Type `43-4C`

| Hex | Move |
|---:|---|
| `43` | Poison Sting |
| `44` | Smog |
| `45` | Acid |
| `46` | Poison Tail |
| `47` | Poison Fang |
| `48` | Sludge |
| `49` | Sludge Bomb |
| `4A` | Poison Gas |
| `4B` | Poison Powder |
| `4C` | Toxic |

### Fighting Type `4D-5A`

| Hex | Move |
|---:|---|
| `4D` | Low Kick |
| `4E` | Rock Smash |
| `4F` | Karate Chop |
| `50` | Double Kick |
| `51` | Revenge |
| `52` | Rolling Kick |
| `53` | Vital Throw |
| `54` | Seismic Toss |
| `55` | Brick Break |
| `56` | Sky Uppercut |
| `57` | Cross Chop |
| `58` | Dynamic Punch |
| `59` | Super Power |
| `5A` | Focus Punch |

### Flying Type `5B-64`

| Hex | Move |
|---:|---|
| `5B` | Peck |
| `5C` | Gust |
| `5D` | Air Cutter |
| `5E` | Wing Attack |
| `5F` | Aerial Ace |
| `60` | Fly |
| `61` | Drill Peck |
| `62` | Bounce |
| `63` | Aero Blast |
| `64` | Sky Attack |

### Psychic Type `65-71`

| Hex | Move |
|---:|---|
| `65` | Confusion |
| `66` | Psy Beam |
| `67` | Mist Ball |
| `68` | Psyshock |
| `69` | Zen Headbutt |
| `6A` | Psychic |
| `6B` | Dream Eater |
| `6C` | Psycho Boost |
| `6D` | Hypnosis |
| `6E` | Rest |
| `6F` | Teleport |
| `70` | Calm Mind |
| `71` | Agility |

### Ghost Type `72-77`

| Hex | Move |
|---:|---|
| `72` | Lick |
| `73` | Astonish |
| `74` | Shadow Punch |
| `75` | Shadow Ball |
| `76` | Shadow Claw |
| `77` | Confuse Ray |

### Dragon Type `78-7D`

| Hex | Move |
|---:|---|
| `78` | Twister |
| `79` | Dragon Rage |
| `7A` | Dragon Breath |
| `7B` | Dragon Claw |
| `7C` | Dragon Pulse |
| `7D` | Dragon Dance |

### Dark Type `7E-81`

| Hex | Move |
|---:|---|
| `7E` | Knock Off |
| `7F` | Faint Attack |
| `80` | Bite |
| `81` | Crunch |

### Steel Type `82-86`

| Hex | Move |
|---:|---|
| `82` | Metal Claw |
| `83` | Steel Wing |
| `84` | Iron Tail |
| `85` | Meteor Mash |
| `86` | Iron Defense |

### Normal Type `87-AF`

| Hex | Move |
|---:|---|
| `87` | SPLASH `(x)` |
| `88` | Rapid Spin |
| `89` | Tackle |
| `8A` | Scratch |
| `8B` | Pound |
| `8C` | Quick Attack |
| `8D` | Pay Day |
| `8E` | Fake Out |
| `8F` | Cut |
| `90` | Swift |
| `91` | Stomp |
| `92` | Crush Claw |
| `93` | Hidden Power |
| `94` | Hyper Fang |
| `95` | Razor Wind |
| `96` | Double Edge |
| `97` | Hyper Beam |
| `98` | Self Destruct |
| `99` | Explosion |
| `9A` | Guillotine |
| `9B` | Horn Drill |
| `9C` | Sing |
| `9D` | Lovely Kiss |
| `9E` | Supersonic |
| `9F` | Sword Dance |
| `A0` | Growl |
| `A1` | Bulk Up |
| `A2` | Defense Curl |
| `A3` | Harden |
| `A4` | Tail Whip |
| `A5` | Charm |
| `A6` | Smoke Screen |
| `A7` | Flash |
| `A8` | Double Team |
| `A9` | Recover |
| `AA` | ENCORE `(x)` |
| `AB` | Roar |
| `AC` | Whirlwind |
| `AD` | `?????` `(x)` |
| `AE` | Curse / maybe Counter |
| `AF` | Strength |

---

## 4. `.pk2` File Format

| Offset | Size / range | Description |
|---:|---|---|
| `0x00` | 1 | Random 1 |
| `0x01` and `0x03` | — | Species |
| `0x04` | 1 | Held item |
| `0x05-0x08` | 4 | Moves |
| `0x09-0x0A` | 2 | Trainer ID |
| `0x0B-0x0D` | 3 | Experience points |
| `0x0E-0x17` | 10 | EVs for stats |
| `0x18-0x19` | 2 | IVs |
| `0x1A-0x1D` | 4 | Move PP |
| `0x1E` | 1 | Friendship |
| `0x1F` | 1 | Pokérus |
| `0x20-0x21` | 2 | Caught data |
| `0x22` | 1 | Level |
| `0x23` | 1 | Status condition |
| `0x26` | 2 | Current HP |
| `0x28` | 2 | Maximum HP |
| `0x2A` | 2 | Attack |
| `0x2C` | 2 | Defense |
| `0x2E` | 2 | Speed |
| `0x30` | 2 | Special Attack |
| `0x32` | 2 | Special Defense |
| `0x33-0x39` | 7 | Trainer name: `80 80 80 80 80 80 80 7` |
| `0x3A-0x3D` | 4 | Useless data: `00 00 00 00` |
| `0x3E-0x44` | 7 | Nickname: `81 81 81 81 81 81 81 81 10` (length 10) |
| `0x45-0x48` | 4 | Useless data: `50 50 50 50 1` |

---

## 5. Special Pokémon IDs

| Index | Name | Pokédex ID | Value |
|---:|---|---:|---:|
| 152 | Raikou | 243 | 4 |
| 153 | Entei | 244 | 4 |
| 154 | Suicune | 245 | 4 |
| 155 | Lugia | 249 | 4 |
| 156 | Ho-Oh | 250 | 4 |

---

## 6. References

- https://www.romhacking.net/forum/index.php?topic=15461.140
- https://www.youtube.com/watch?v=WJmAl2DNvU8
- https://www.youtube.com/watch?v=wh7F7w8zf5o
