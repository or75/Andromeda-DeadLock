#pragma once

/*
00007FFB8BDDCA9 | 44:8BB8 70650000               | mov r15d,dword ptr ds:[rax+0x6570]               | offset m_nSequenceNumber
00007FFB8BDDCAA | 41:8BD7                        | mov edx,r15d                                     |
00007FFB8BDDCAA | E8 2307E2FF                    | call client.7FFB8BBFD1D0                         |
00007FFB8BDDCAA | 48:8B0D E4A72201               | mov rcx,qword ptr ds:[0x7FFB8D007298]            |
00007FFB8BDDCAB | 45:33E4                        | xor r12d,r12d                                    |
00007FFB8BDDCAB | 48:8945 97                     | mov qword ptr ss:[rbp-0x69],rax                  |
*/
// 44 8B B8 ? ? ? ? 41 8B D7 E8 ? ? ? ? 48 8B ? ? ? ? ? 45 33 E4 48 89 45
static constexpr auto g_OFFSET_CUserCmdArray_m_nSequenceNumber = 0x6570;
