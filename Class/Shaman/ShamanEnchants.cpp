#include "ShamanEnchants.h"

#include "Shaman.h"
#include "Utils/Check.h"

ShamanEnchants::ShamanEnchants(Shaman* shaman) :
    CharacterEnchants(shaman)
{}

QVector<EnchantName::Name> ShamanEnchants::get_available_enchants(const int equipment_slot) const {
    switch (equipment_slot) {
    case EquipmentSlot::MAINHAND: {
        QVector<EnchantName::Name> enchants {
            EnchantName::Name::Crusader,
            EnchantName::Name::FieryWeapon,
            EnchantName::Name::EnchantWeaponStrength,
            EnchantName::Name::SuperiorStriking,
            EnchantName::Name::EnchantWeaponSpellPower,
        };

        if (has_2hand()) {
            enchants.append({
                                EnchantName::Name::Enchant2HWeaponAgility,
                                EnchantName::Name::Enchant2HWeaponSuperiorImpact,
                                EnchantName::Name::IronCounterweight,
                            });
        }
        else
           enchants.append(EnchantName::Name::EnchantWeaponAgility);

        return enchants;
    }
    case EquipmentSlot::OFFHAND:
    case EquipmentSlot::RANGED:
        return {};
    case EquipmentSlot::HEAD:
    case EquipmentSlot::LEGS:
        return {
            EnchantName::Name::ArcanumOfFocus,
            EnchantName::Name::ArcanumOfRapidity,
            EnchantName::Name::LesserArcanumOfVoracityStrength
        };
    case EquipmentSlot::SHOULDERS:
        return {
            EnchantName::Name::MightOfTheScourge,
            EnchantName::Name::ZandalarSignetOfMight,
            EnchantName::Name::ZandalarSignetOfMojo,
        };
    case EquipmentSlot::BACK:
        return {
            EnchantName::Name::EnchantCloakLesserAgility
        };
    case EquipmentSlot::WRIST:
        return {
            EnchantName::Name::EnchantBracerManaRegeneration,
            EnchantName::Name::EnchantBracerSuperiorStrength,
            EnchantName::Name::EnchantBracerMinorAgility,
        };
    case EquipmentSlot::GLOVES:
        return {
            EnchantName::Name::EnchantGlovesSuperiorAgility,
            EnchantName::Name::EnchantGlovesMinorHaste,
            EnchantName::Name::EnchantGlovesGreaterStrength
        };
    case EquipmentSlot::CHEST:
        return {
            EnchantName::Name::EnchantChestGreaterStats
        };
    case EquipmentSlot::BOOTS:
        return {
            EnchantName::Name::EnchantBootsMinorSpeed,
            EnchantName::Name::EnchantBootsGreaterAgility,
            EnchantName::Name::EnchantBootsSpirit,
        };
    }

    check(false, "ShamanEnchants::get_available_enchants reached end of switch");
    return {};
}

QVector<EnchantName::Name> ShamanEnchants::get_available_temp_enchants(const int equipment_slot) const {
    switch (equipment_slot) {
    case EquipmentSlot::MAINHAND: {
        QVector<EnchantName::Name> enchants {
            EnchantName::ElementalSharpeningStone,
            EnchantName::ConsecratedSharpeningStone,
            EnchantName::ShadowOil,
        };
        if (has_sharp_weapon(equipment_slot))
            enchants.prepend(EnchantName::DenseSharpeningStone);
        else if (has_blunt_weapon(equipment_slot))
            enchants.prepend(EnchantName::SolidWeightstone);
        return enchants;
    }
    case EquipmentSlot::OFFHAND:
        return {};
    }

    check(false, "ShamanEnchants::get_available_temp_enchants reached end of switch");
    return {};
}
