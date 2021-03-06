PGDMP     "                 
    x            main    13.0    13.0 #    �           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            �           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            �           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            �           1262    16394    main    DATABASE     `   CREATE DATABASE main WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE = 'Polish_Poland.1250';
    DROP DATABASE main;
                postgres    false            �            1259    16422    active_errors    TABLE     �   CREATE TABLE public.active_errors (
    id integer NOT NULL,
    source text,
    value text,
    hint text,
    noticable boolean,
    noticed boolean,
    log boolean,
    showinbar boolean,
    clicked boolean
);
 !   DROP TABLE public.active_errors;
       public         heap    postgres    false            �            1259    16425    active_errors_id_seq    SEQUENCE     }   CREATE SEQUENCE public.active_errors_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 +   DROP SEQUENCE public.active_errors_id_seq;
       public          postgres    false    206            �           0    0    active_errors_id_seq    SEQUENCE OWNED BY     M   ALTER SEQUENCE public.active_errors_id_seq OWNED BY public.active_errors.id;
          public          postgres    false    207            �            1259    16397    inputs    TABLE     �   CREATE TABLE public.inputs (
    id integer NOT NULL,
    name text,
    inputid integer,
    connectionid integer,
    type integer,
    posx real,
    posy real
);
    DROP TABLE public.inputs;
       public         heap    postgres    false            �            1259    16395    inputs_id_seq    SEQUENCE     �   CREATE SEQUENCE public.inputs_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 $   DROP SEQUENCE public.inputs_id_seq;
       public          postgres    false    201            �           0    0    inputs_id_seq    SEQUENCE OWNED BY     ?   ALTER SEQUENCE public.inputs_id_seq OWNED BY public.inputs.id;
          public          postgres    false    200            �            1259    16406 	   integrals    TABLE     C  CREATE TABLE public.integrals (
    id integer NOT NULL,
    name text,
    ip text,
    posx real NOT NULL,
    posy real NOT NULL,
    port integer,
    image integer,
    zones text,
    pass text,
    malf_list text,
    alarm_list text,
    armed_list text,
    conn integer,
    ver integer,
    input_states text
);
    DROP TABLE public.integrals;
       public         heap    postgres    false            �           0    0    COLUMN integrals.ver    ACL     6   GRANT ALL(ver) ON TABLE public.integrals TO postgres;
          public          postgres    false    203            �            1259    16404    integrals_id_seq    SEQUENCE     �   CREATE SEQUENCE public.integrals_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 '   DROP SEQUENCE public.integrals_id_seq;
       public          postgres    false    203            �           0    0    integrals_id_seq    SEQUENCE OWNED BY     E   ALTER SEQUENCE public.integrals_id_seq OWNED BY public.integrals.id;
          public          postgres    false    202            �            1259    16415    log    TABLE     i   CREATE TABLE public.log (
    id integer NOT NULL,
    date timestamp without time zone,
    msg text
);
    DROP TABLE public.log;
       public         heap    postgres    false            �            1259    16413 
   log_id_seq    SEQUENCE     �   CREATE SEQUENCE public.log_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 !   DROP SEQUENCE public.log_id_seq;
       public          postgres    false    205            �           0    0 
   log_id_seq    SEQUENCE OWNED BY     9   ALTER SEQUENCE public.log_id_seq OWNED BY public.log.id;
          public          postgres    false    204            �            1259    24680    requests    TABLE     �   CREATE TABLE public.requests (
    cmd integer,
    dbid integer,
    "values" text,
    fulfill integer,
    pass text,
    id integer NOT NULL
);
    DROP TABLE public.requests;
       public         heap    postgres    false            �            1259    32806    requests_id_seq    SEQUENCE     �   CREATE SEQUENCE public.requests_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.requests_id_seq;
       public          postgres    false    208            �           0    0    requests_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.requests_id_seq OWNED BY public.requests.id;
          public          postgres    false    209            B           2604    16434    active_errors id    DEFAULT     t   ALTER TABLE ONLY public.active_errors ALTER COLUMN id SET DEFAULT nextval('public.active_errors_id_seq'::regclass);
 ?   ALTER TABLE public.active_errors ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    207    206            ?           2604    16400 	   inputs id    DEFAULT     f   ALTER TABLE ONLY public.inputs ALTER COLUMN id SET DEFAULT nextval('public.inputs_id_seq'::regclass);
 8   ALTER TABLE public.inputs ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    201    200    201            @           2604    16409    integrals id    DEFAULT     l   ALTER TABLE ONLY public.integrals ALTER COLUMN id SET DEFAULT nextval('public.integrals_id_seq'::regclass);
 ;   ALTER TABLE public.integrals ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    203    202    203            A           2604    16418    log id    DEFAULT     `   ALTER TABLE ONLY public.log ALTER COLUMN id SET DEFAULT nextval('public.log_id_seq'::regclass);
 5   ALTER TABLE public.log ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    205    204    205            C           2604    32808    requests id    DEFAULT     j   ALTER TABLE ONLY public.requests ALTER COLUMN id SET DEFAULT nextval('public.requests_id_seq'::regclass);
 :   ALTER TABLE public.requests ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    209    208            �          0    16422    active_errors 
   TABLE DATA           m   COPY public.active_errors (id, source, value, hint, noticable, noticed, log, showinbar, clicked) FROM stdin;
    public          postgres    false    206   �#       �          0    16397    inputs 
   TABLE DATA           S   COPY public.inputs (id, name, inputid, connectionid, type, posx, posy) FROM stdin;
    public          postgres    false    201   �$       �          0    16406 	   integrals 
   TABLE DATA           �   COPY public.integrals (id, name, ip, posx, posy, port, image, zones, pass, malf_list, alarm_list, armed_list, conn, ver, input_states) FROM stdin;
    public          postgres    false    203   Q%       �          0    16415    log 
   TABLE DATA           ,   COPY public.log (id, date, msg) FROM stdin;
    public          postgres    false    205   �%       �          0    24680    requests 
   TABLE DATA           J   COPY public.requests (cmd, dbid, "values", fulfill, pass, id) FROM stdin;
    public          postgres    false    208   -1       �           0    0    active_errors_id_seq    SEQUENCE SET     C   SELECT pg_catalog.setval('public.active_errors_id_seq', 72, true);
          public          postgres    false    207            �           0    0    inputs_id_seq    SEQUENCE SET     ;   SELECT pg_catalog.setval('public.inputs_id_seq', 4, true);
          public          postgres    false    200            �           0    0    integrals_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.integrals_id_seq', 2, true);
          public          postgres    false    202            �           0    0 
   log_id_seq    SEQUENCE SET     :   SELECT pg_catalog.setval('public.log_id_seq', 187, true);
          public          postgres    false    204            �           0    0    requests_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.requests_id_seq', 8, true);
          public          postgres    false    209            �   �   x�ՎA
�0E��)� 2$k��[�n�d�QIJ(����sk{/k���_x�_�j���r��Iq`�Z(�f9�5r�����G
c7]�8�h�7���gʛ�זMki��e����~�^�<A(��n��b�;���8��KzG�emQs�(����N�+�V���U���;����I���K�      �   �   x�E�;�@D��]�֟��3�U����>�DM�f��׶��� PC�f@5�$H���xn�c|$�r���8,迿\����j���U(���RgXoM��a}��}�5�]�NO���'��,��_��9-&�      �   �   x�m�1
A���)<AH2�ɤ�J��f
��A�ӻ�""�t���\���P�ڈ�2�2qqX2���p���}%��Q�(v�����'�Z2YSxq�p�.	�����/ �$�PsP�"&/�6�I?L��jLJ {�6���O�4PJ���1�      �   "  x�͝�n������q�(����m���.���B�JVc�hPR�8�E�a��1� 9e��J)�fuψ�ɮ�ؖU��ͯ����`��f�5gӅ6��r��].��j]e媬��7uu�Z��n�7��u���ٺ�ߖ����ȸ3������Y��`[�,W�W����6�z��r��e6��Z���}�ZUE���9�W__��w�2�D��dC��'φ���� y�C&φ���,���u9��o�U9�/��E�o�J��|���_Ͳoo���j��U��ۛ�vQ�YU�Ǘ.g��cva#T��$er&EPn8�����C���R�Kփ����زJ�g����>س��$X� B�lZmi���
 "}>�O�+I�@l�|��O�o(�E>D$}�DH��AQ�q��1\�|����&��$������0�*8�O%�����|�A�"�O��a�|>�i�!�����O�7;E>�Z�|`�r^0`��?�O�,E_a�H�������M���u}����UY�C+���������W�mU�����r�}W/6sZ�x�t]^���_/�l��\�����z��a;����#�Ȥ�AJF�4��ꘕ;߿lz?y���_����@��ߵ�����pY4%�&%�;���vU{
��ֆ�����E0N�o��Mu{����Ƚ��b��E�hf�#K�˂-|MO��#X�X��Z@)����]�Nئ?�L9LV�au>}X����=�7uy�����g����ֽZ/��ͪʮ<��ns]B�#˯2��ο��n�p��V�?���/��=��n��r��K�[(GĜ����28��f��(�"%v�Ϻ0��՟31GĊ��	j�����꺪;����w�]8���
��E�D;c���;Z�h���ɱ�}E���a�h�n�*�ŢU9�''�m�L!���s�<-S4r��V�8魗����y�N�yf+�1�0� �O�.��t	J�9X��/	}_�S)��j[������A]]|��7�W������H}q��S��7Ǿ��o<�=�j}�;'��Sߤ�V���������\���z���}U��.nv�s���8]-�9�O�{��x���A�k�!c;�x34}-b
�;rr����}�z�U�<�O����(�4�5���?�^8�o�1d��w��x
C�iy��a��-���=2a`$Q&P}ڇ���=���q�ǅ�}�������?��ٛ�z���Y�v1��S�����]���M����72|c��xc��XÌ�o��ÚX�}�s��O7ˇw)�ψڢ�G@��4�1����)��6a3.��:&y:\B��:��I��<$�	�$IBd�d��s �B �;�됄��1���eLH�{���b](A�!��`D��*�vp:yB�*�Df���R�m~�O�*�DV;L�Hյ�L�H�����	�R��JI�,U !(!X�0I"U��
$��!KU�O%O��R��t�
��v�N���IϕKcb�C�HU�Iύcb����F��	1��+��İô�J��"$���(!�GH���1NGGl���1[�%*a4��R`�I�N���0x��Rt���I��2!�H��W6ĠR.$Q�kV��lvR$D󐄠f�"�P$�7-C��1��50�$Hn�#$�LW���|L2#�M�$�(�~&�f͏�Я�H����OH�0FN4(��`�!��J�:�e�$��G�0�*!:B�~�4�1���J�!I�R�-�PDӷ�����e1hJ����%�`���%M�k�T�$}�k�T�M��`����V�1�T�a]��`�I�Z�`�
��2���,QY�\@�].�C��޿�~�vr2Z	��}d-p���6٧��k��%Xj��걙�i�B����5�Ҋ�%u[�N�֮�`�`�H�:�DH�{�Z���jv�"$��X��N�lo;�#�F.yD�A���I�a�ZXNEH
���h��%Y�����l��		$J�@�a�jF�m�3lQ�B�o�;j"�{�#gFM΁Ū%Q��6+����8��5�y�p�GP(Rb0�I���3�C[�����J���‵4�8����qH��M�A�H�
9���T(ب�B��`�>n&&H	6*�4�8֫��ٍ)�z��N`�*I����WE�x��W�-���U5+�ӧ��sh����z���`\`����G����T5;�I.F T3�/F`S��@�1.��������R$Q(v�ˎ?f��b��!qdK�x�KA!0���$��9�<h���G2����e&�s���$�pq�!�g]�ܿ]3na�y$�`�It��;h��ǅ>��80��������������������l��4EIRس��,���M۬�")Iص0�r��(�VB�9ص 3ʃ	��u=�"�n�@�.Q%�/;�JBjv�g[G&�����/{����3٨nm�]�GrA�k�)�����0�<(q0	v��=�%0J9Ů����ϊ�e	��&�e�e�];R8}��9�=�؎Y���Swϊ,Qd~8����n-:����ݭEp�2�52L�a�z��`!����ʩ#s�r�B��3�tw�r���0؟ 3ʣ�`��Cک�w+`z.����W�N�&P��}���$�_퐹ɑa����$P�232L�\�{{\(׵4�H��3�$iyR�d���5`���02��3|d��=F�0�d��o��f�@r�Alc4$�����y;�>u��...�'s*�      �   &   x�3�4�4 BC �4�2@��r�Q�f�\s�=... �6
Y     