# cs2 internal base

Prosty internal (DLL) pod CS2 z menu ImGui (DirectX 11) i bunnyhopem przeniesionym z
[nexnith/internal_bhop](https://github.com/nexnith/internal_bhop).

## Funkcje

- Hook `IDXGISwapChain::Present` / `ResizeBuffers` przez MinHook, menu ImGui (Win32 + DX11)
- **Bunnyhop**: wł./wył., wybór klawisza (Space / Mouse 4 / Mouse 5 / Left Alt / C), opóźnienie puszczenia skoku
- `INSERT` – pokaż/ukryj menu (gdy menu jest otwarte, input do gry jest blokowany, a bhop wstrzymany)
- `END` albo przycisk **Unload** – wyładowanie DLL

## Struktura

```
src/
  dllmain.cpp         wejście DLL, wątek z pętlą funkcji, unload
  core/hooks.cpp      hook DX11, WndProc, inicjalizacja ImGui
  core/config.h       ustawienia zmieniane z menu
  features/bhop.cpp   bunnyhop
  ui/menu.cpp         menu ImGui
  sdk/offsets.h       offsety
  sdk/memory.h        bezpieczny odczyt/zapis pamięci
ext/
  imgui/              Dear ImGui v1.91.9 (MIT)
  minhook/            MinHook (BSD-2)
```

Nowe funkcje: dodaj plik w `src/features/`, ustawienia w `core/config.h`, zakładkę/checkbox w
`ui/menu.cpp` i wywołanie w pętli w `dllmain.cpp`.

## Budowanie

- **Visual Studio 2022**: otwórz `cs2_internal.sln`, wybierz `Release | x64`, Build. DLL ląduje w `bin/Release/`.
- **CMake**: `cmake -B build -A x64 && cmake --build build --config Release`

## Offsety

Offsety w `src/sdk/offsets.h` zmieniają się praktycznie z każdą aktualizacją CS2. Po patchu weź
aktualne wartości z [a2x/cs2-dumper](https://github.com/a2x/cs2-dumper)
(`buttons.hpp` → `jump`, `offsets.hpp` → `dwLocalPlayerPawn`, `client_dll.hpp` → `m_fFlags`).

## Uwagi

- Działa tylko z rendererem DX11 (domyślny w CS2). Z `-vulkan` hook się nie założy.
- Projekt nie zawiera żadnego obejścia anti-cheata – używaj tylko offline / na prywatnych serwerach
  (`-insecure`). Na serwerach VAC grozi ban.
