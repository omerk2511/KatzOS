#include "idt.h"

idt_entry_t idt_entries[256];

void insert_idt_entry(int i, void *isr) {
    idt_entries[i].lower_offset = ((unsigned int) isr) & 0xffff;
    idt_entries[i].selector = 0x08;
    idt_entries[i].zeros = 0;
    idt_entries[i].flags = 0b11100001;
    idt_entries[i].higher_offset = ((unsigned int) isr) >> 4;
}

void init_idt() {
    idt_info_t idt_info;

    idt_info.size = sizeof(idt_entry_t) * 256 - 1;
    idt_info.offset = idt_entries;

    insert_idt_entry(0, isr0);
    insert_idt_entry(1, isr1);
    insert_idt_entry(2, isr2);
    insert_idt_entry(3, isr3);
    insert_idt_entry(4, isr4);
    insert_idt_entry(5, isr5);
    insert_idt_entry(6, isr6);
    insert_idt_entry(7, isr7);
    insert_idt_entry(8, isr8);
    insert_idt_entry(9, isr9);
    insert_idt_entry(10, isr10);
    insert_idt_entry(11, isr11);
    insert_idt_entry(12, isr12);
    insert_idt_entry(13, isr13);
    insert_idt_entry(14, isr14);
    insert_idt_entry(15, isr15);
    insert_idt_entry(16, isr16);
    insert_idt_entry(17, isr17);
    insert_idt_entry(18, isr18);
    insert_idt_entry(19, isr19);
    insert_idt_entry(20, isr20);
    insert_idt_entry(21, isr21);
    insert_idt_entry(22, isr22);
    insert_idt_entry(23, isr23);
    insert_idt_entry(24, isr24);
    insert_idt_entry(25, isr25);
    insert_idt_entry(26, isr26);
    insert_idt_entry(27, isr27);
    insert_idt_entry(28, isr28);
    insert_idt_entry(29, isr29);
    insert_idt_entry(30, isr30);
    insert_idt_entry(31, isr31);
    insert_idt_entry(32, isr32);
    insert_idt_entry(33, isr33);
    insert_idt_entry(34, isr34);
    insert_idt_entry(35, isr35);
    insert_idt_entry(36, isr36);
    insert_idt_entry(37, isr37);
    insert_idt_entry(38, isr38);
    insert_idt_entry(39, isr39);
    insert_idt_entry(40, isr40);
    insert_idt_entry(41, isr41);
    insert_idt_entry(42, isr42);
    insert_idt_entry(43, isr43);
    insert_idt_entry(44, isr44);
    insert_idt_entry(45, isr45);
    insert_idt_entry(46, isr46);
    insert_idt_entry(47, isr47);
    insert_idt_entry(48, isr48);
    insert_idt_entry(49, isr49);
    insert_idt_entry(50, isr50);
    insert_idt_entry(51, isr51);
    insert_idt_entry(52, isr52);
    insert_idt_entry(53, isr53);
    insert_idt_entry(54, isr54);
    insert_idt_entry(55, isr55);
    insert_idt_entry(56, isr56);
    insert_idt_entry(57, isr57);
    insert_idt_entry(58, isr58);
    insert_idt_entry(59, isr59);
    insert_idt_entry(60, isr60);
    insert_idt_entry(61, isr61);
    insert_idt_entry(62, isr62);
    insert_idt_entry(63, isr63);
    insert_idt_entry(64, isr64);
    insert_idt_entry(65, isr65);
    insert_idt_entry(66, isr66);
    insert_idt_entry(67, isr67);
    insert_idt_entry(68, isr68);
    insert_idt_entry(69, isr69);
    insert_idt_entry(70, isr70);
    insert_idt_entry(71, isr71);
    insert_idt_entry(72, isr72);
    insert_idt_entry(73, isr73);
    insert_idt_entry(74, isr74);
    insert_idt_entry(75, isr75);
    insert_idt_entry(76, isr76);
    insert_idt_entry(77, isr77);
    insert_idt_entry(78, isr78);
    insert_idt_entry(79, isr79);
    insert_idt_entry(80, isr80);
    insert_idt_entry(81, isr81);
    insert_idt_entry(82, isr82);
    insert_idt_entry(83, isr83);
    insert_idt_entry(84, isr84);
    insert_idt_entry(85, isr85);
    insert_idt_entry(86, isr86);
    insert_idt_entry(87, isr87);
    insert_idt_entry(88, isr88);
    insert_idt_entry(89, isr89);
    insert_idt_entry(90, isr90);
    insert_idt_entry(91, isr91);
    insert_idt_entry(92, isr92);
    insert_idt_entry(93, isr93);
    insert_idt_entry(94, isr94);
    insert_idt_entry(95, isr95);
    insert_idt_entry(96, isr96);
    insert_idt_entry(97, isr97);
    insert_idt_entry(98, isr98);
    insert_idt_entry(99, isr99);
    insert_idt_entry(100, isr100);
    insert_idt_entry(101, isr101);
    insert_idt_entry(102, isr102);
    insert_idt_entry(103, isr103);
    insert_idt_entry(104, isr104);
    insert_idt_entry(105, isr105);
    insert_idt_entry(106, isr106);
    insert_idt_entry(107, isr107);
    insert_idt_entry(108, isr108);
    insert_idt_entry(109, isr109);
    insert_idt_entry(110, isr110);
    insert_idt_entry(111, isr111);
    insert_idt_entry(112, isr112);
    insert_idt_entry(113, isr113);
    insert_idt_entry(114, isr114);
    insert_idt_entry(115, isr115);
    insert_idt_entry(116, isr116);
    insert_idt_entry(117, isr117);
    insert_idt_entry(118, isr118);
    insert_idt_entry(119, isr119);
    insert_idt_entry(120, isr120);
    insert_idt_entry(121, isr121);
    insert_idt_entry(122, isr122);
    insert_idt_entry(123, isr123);
    insert_idt_entry(124, isr124);
    insert_idt_entry(125, isr125);
    insert_idt_entry(126, isr126);
    insert_idt_entry(127, isr127);
    insert_idt_entry(128, isr128);
    insert_idt_entry(129, isr129);
    insert_idt_entry(130, isr130);
    insert_idt_entry(131, isr131);
    insert_idt_entry(132, isr132);
    insert_idt_entry(133, isr133);
    insert_idt_entry(134, isr134);
    insert_idt_entry(135, isr135);
    insert_idt_entry(136, isr136);
    insert_idt_entry(137, isr137);
    insert_idt_entry(138, isr138);
    insert_idt_entry(139, isr139);
    insert_idt_entry(140, isr140);
    insert_idt_entry(141, isr141);
    insert_idt_entry(142, isr142);
    insert_idt_entry(143, isr143);
    insert_idt_entry(144, isr144);
    insert_idt_entry(145, isr145);
    insert_idt_entry(146, isr146);
    insert_idt_entry(147, isr147);
    insert_idt_entry(148, isr148);
    insert_idt_entry(149, isr149);
    insert_idt_entry(150, isr150);
    insert_idt_entry(151, isr151);
    insert_idt_entry(152, isr152);
    insert_idt_entry(153, isr153);
    insert_idt_entry(154, isr154);
    insert_idt_entry(155, isr155);
    insert_idt_entry(156, isr156);
    insert_idt_entry(157, isr157);
    insert_idt_entry(158, isr158);
    insert_idt_entry(159, isr159);
    insert_idt_entry(160, isr160);
    insert_idt_entry(161, isr161);
    insert_idt_entry(162, isr162);
    insert_idt_entry(163, isr163);
    insert_idt_entry(164, isr164);
    insert_idt_entry(165, isr165);
    insert_idt_entry(166, isr166);
    insert_idt_entry(167, isr167);
    insert_idt_entry(168, isr168);
    insert_idt_entry(169, isr169);
    insert_idt_entry(170, isr170);
    insert_idt_entry(171, isr171);
    insert_idt_entry(172, isr172);
    insert_idt_entry(173, isr173);
    insert_idt_entry(174, isr174);
    insert_idt_entry(175, isr175);
    insert_idt_entry(176, isr176);
    insert_idt_entry(177, isr177);
    insert_idt_entry(178, isr178);
    insert_idt_entry(179, isr179);
    insert_idt_entry(180, isr180);
    insert_idt_entry(181, isr181);
    insert_idt_entry(182, isr182);
    insert_idt_entry(183, isr183);
    insert_idt_entry(184, isr184);
    insert_idt_entry(185, isr185);
    insert_idt_entry(186, isr186);
    insert_idt_entry(187, isr187);
    insert_idt_entry(188, isr188);
    insert_idt_entry(189, isr189);
    insert_idt_entry(190, isr190);
    insert_idt_entry(191, isr191);
    insert_idt_entry(192, isr192);
    insert_idt_entry(193, isr193);
    insert_idt_entry(194, isr194);
    insert_idt_entry(195, isr195);
    insert_idt_entry(196, isr196);
    insert_idt_entry(197, isr197);
    insert_idt_entry(198, isr198);
    insert_idt_entry(199, isr199);
    insert_idt_entry(200, isr200);
    insert_idt_entry(201, isr201);
    insert_idt_entry(202, isr202);
    insert_idt_entry(203, isr203);
    insert_idt_entry(204, isr204);
    insert_idt_entry(205, isr205);
    insert_idt_entry(206, isr206);
    insert_idt_entry(207, isr207);
    insert_idt_entry(208, isr208);
    insert_idt_entry(209, isr209);
    insert_idt_entry(210, isr210);
    insert_idt_entry(211, isr211);
    insert_idt_entry(212, isr212);
    insert_idt_entry(213, isr213);
    insert_idt_entry(214, isr214);
    insert_idt_entry(215, isr215);
    insert_idt_entry(216, isr216);
    insert_idt_entry(217, isr217);
    insert_idt_entry(218, isr218);
    insert_idt_entry(219, isr219);
    insert_idt_entry(220, isr220);
    insert_idt_entry(221, isr221);
    insert_idt_entry(222, isr222);
    insert_idt_entry(223, isr223);
    insert_idt_entry(224, isr224);
    insert_idt_entry(225, isr225);
    insert_idt_entry(226, isr226);
    insert_idt_entry(227, isr227);
    insert_idt_entry(228, isr228);
    insert_idt_entry(229, isr229);
    insert_idt_entry(230, isr230);
    insert_idt_entry(231, isr231);
    insert_idt_entry(232, isr232);
    insert_idt_entry(233, isr233);
    insert_idt_entry(234, isr234);
    insert_idt_entry(235, isr235);
    insert_idt_entry(236, isr236);
    insert_idt_entry(237, isr237);
    insert_idt_entry(238, isr238);
    insert_idt_entry(239, isr239);
    insert_idt_entry(240, isr240);
    insert_idt_entry(241, isr241);
    insert_idt_entry(242, isr242);
    insert_idt_entry(243, isr243);
    insert_idt_entry(244, isr244);
    insert_idt_entry(245, isr245);
    insert_idt_entry(246, isr246);
    insert_idt_entry(247, isr247);
    insert_idt_entry(248, isr248);
    insert_idt_entry(249, isr249);
    insert_idt_entry(250, isr250);
    insert_idt_entry(251, isr251);
    insert_idt_entry(252, isr252);
    insert_idt_entry(253, isr253);
    insert_idt_entry(254, isr254);
    insert_idt_entry(255, isr255);

    load_idt(&idt_info);
}