import matplotlib.pyplot as plt

# amdahl hesaplama fonksiyonu
def amdahl_law(seri_oran, islemci_sayisi):
    return 1 / ((1 - seri_oran) + (seri_oran / islemci_sayisi))

seri_oran = float(input("Paralelleştirilemeyen kısmın oranını gir (0 ile 1 arasında bir sayı yaz): "))
maks_islemci = int(input("Maksimum işlemci sayısını gir (örneğin 10 veya 16): "))


islemci_sayilari = range(1, maks_islemci + 1)  # İşlemci sayıları 1'den max'a kadar
hizlanmalar = [amdahl_law(seri_oran, n) for n in islemci_sayilari]


print("\nİşlemci Sayısı ve Hızlanma Faktörleri:")
for i, s in zip(islemci_sayilari, hizlanmalar):
    print(f"{i} işlemci: {s:.2f} kat hızlanma")

# Hızlanmayı görselleştir
plt.plot(islemci_sayilari, hizlanmalar, marker='o')
plt.title("Amdahl Yasası: İşlemci Sayısına Göre Hızlanma")
plt.xlabel("İşlemci Sayısı")
plt.ylabel("Hızlanma Faktörü")
plt.grid()
plt.show()
