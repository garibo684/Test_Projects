#!/bin/sh

# Display usage
cpack_usage()
{
  cat <<EOF
Usage: $0 [options]
Options: [defaults in brackets after descriptions]
  --help            print this message
  --version         print cmake installer version
  --prefix=dir      directory in which to install
  --include-subdir  include the Currency_Converter--Linux subdirectory
  --exclude-subdir  exclude the Currency_Converter--Linux subdirectory
  --skip-license    accept license
EOF
  exit 1
}

cpack_echo_exit()
{
  echo $1
  exit 1
}

# Display version
cpack_version()
{
  echo "Currency_Converter Installer Version: , Copyright (c) Humanity"
}

# Helper function to fix windows paths.
cpack_fix_slashes ()
{
  echo "$1" | sed 's/\\/\//g'
}

interactive=TRUE
cpack_skip_license=FALSE
cpack_include_subdir=""
for a in "$@"; do
  if echo $a | grep "^--prefix=" > /dev/null 2> /dev/null; then
    cpack_prefix_dir=`echo $a | sed "s/^--prefix=//"`
    cpack_prefix_dir=`cpack_fix_slashes "${cpack_prefix_dir}"`
  fi
  if echo $a | grep "^--help" > /dev/null 2> /dev/null; then
    cpack_usage
  fi
  if echo $a | grep "^--version" > /dev/null 2> /dev/null; then
    cpack_version
    exit 2
  fi
  if echo $a | grep "^--include-subdir" > /dev/null 2> /dev/null; then
    cpack_include_subdir=TRUE
  fi
  if echo $a | grep "^--exclude-subdir" > /dev/null 2> /dev/null; then
    cpack_include_subdir=FALSE
  fi
  if echo $a | grep "^--skip-license" > /dev/null 2> /dev/null; then
    cpack_skip_license=TRUE
  fi
done

if [ "x${cpack_include_subdir}x" != "xx" -o "x${cpack_skip_license}x" = "xTRUEx" ]
then
  interactive=FALSE
fi

cpack_version
echo "This is a self-extracting archive."
toplevel="`pwd`"
if [ "x${cpack_prefix_dir}x" != "xx" ]
then
  toplevel="${cpack_prefix_dir}"
fi

echo "The archive will be extracted to: ${toplevel}"

if [ "x${interactive}x" = "xTRUEx" ]
then
  echo ""
  echo "If you want to stop extracting, please press <ctrl-C>."

  if [ "x${cpack_skip_license}x" != "xTRUEx" ]
  then
    more << '____cpack__here_doc____'
Making Some Apps?

____cpack__here_doc____
    echo
    while true
      do
        echo "Do you accept the license? [yn]: "
        read line leftover
        case ${line} in
          y* | Y*)
            cpack_license_accepted=TRUE
            break;;
          n* | N* | q* | Q* | e* | E*)
            echo "License not accepted. Exiting ..."
            exit 1;;
        esac
      done
  fi

  if [ "x${cpack_include_subdir}x" = "xx" ]
  then
    echo "By default the Currency_Converter will be installed in:"
    echo "  \"${toplevel}/Currency_Converter--Linux\""
    echo "Do you want to include the subdirectory Currency_Converter--Linux?"
    echo "Saying no will install in: \"${toplevel}\" [Yn]: "
    read line leftover
    cpack_include_subdir=TRUE
    case ${line} in
      n* | N*)
        cpack_include_subdir=FALSE
    esac
  fi
fi

if [ "x${cpack_include_subdir}x" = "xTRUEx" ]
then
  toplevel="${toplevel}/Currency_Converter--Linux"
  mkdir -p "${toplevel}"
fi
echo
echo "Using target directory: ${toplevel}"
echo "Extracting, please wait..."
echo ""

# take the archive portion of this file and pipe it to tar
# the NUMERIC parameter in this command should be one more
# than the number of lines in this header file
# there are tails which don't understand the "-n" argument, e.g. on SunOS
# OTOH there are tails which complain when not using the "-n" argument (e.g. GNU)
# so at first try to tail some file to see if tail fails if used with "-n"
# if so, don't use "-n"
use_new_tail_syntax="-n"
tail $use_new_tail_syntax +1 "$0" > /dev/null 2> /dev/null || use_new_tail_syntax=""

extractor="pax -r"
command -v pax > /dev/null 2> /dev/null || extractor="tar xf -"

tail $use_new_tail_syntax +151 "$0" | gunzip | (cd "${toplevel}" && ${extractor}) || cpack_echo_exit "Problem unpacking the Currency_Converter--Linux"

echo "Unpacking finished successfully"

exit 0
#-----------------------------------------------------------
#      Start of TAR.GZ file
#-----------------------------------------------------------;
� T��d �]|TŹ?��%!�C*+��º�7 � �PT�a��I�&�q�,+-�hK�5>K��ƫmm���mi}4B�؟zc_rk[c�6)��^d�7��sf�������3��7�<Μ�3�	��-�@�2���UZ\�@�H	�.�P�.t9\�Oq��(>�J��i�(��D��ҝ(^�ܿH���G��Q-u6�x`���"y��Ji��J�@����k�51	���~[����sD��`vv������A��_�v8[">�QA�e�Hk������4GL̟Ӣ�pӅ/s�EN�~�?������
��p�j�Y�D��]P��WiI)�������4���`c(t���^����\�J�Z�|u�#{���P=E���5�jVWխ��g�*N64��gt�©���%����������h4�oV���Ȗ1t����n��]n4����O%|ɳr��b�y��H���/�����<�J���:��(�3�t"�o5�,��o���"=[1RG3��Ϯ	F��%��х��]�g�|��B�d7R>�ͦ�4~��v�z�e�Yi�4ߎ�F�)�g�+�rE���b�f�N�K#e�־��S^5��VNx���)+�*�7J9������'k�m6#e�첖PCI�e-��-�p|��Me%sK�����@�ˡ�>u�z�n=�b�V�3y�z"�G��{����.X�����'�-9����ToM���V�^��HI�/�r\;0��l�{5�Jkѝo��cl��>?��M��6s|�b�7X��{%�nI���?K"�=|���u�r\���0�_S��%rΗ���J�4I��[�������$��[��XR��%�$r4��h�8��K��ȉI��H�ϑ�S$��')���i�� <O�s)�=tB�*�g�2])_O�<6ѨjSk$��U����ZYW���`S(�����H8X�kh	�8��V���JUտi,�
|��_%��T�k5���싪Z��b�~O����#�m�h�S�D��w�Z��6X�Bl�S�Q���𤕪Pu��1�T���6�?�m��b!����_�$Kݞ��jE�p��L<,k�BR^
�Z+��:��-f��H-�;Z4��*�Dφ:��L��
\���F_4���Q}Zr����E��5G#�Px��%P}Ѧxk0���U��TP"XTi�r����jj#��GA����6a���oF]n�&�-�E� W۬np���B�џ�q�agכC��
hs��*O���u�PŪ�B�r���<ԄP��Դ�R�F��}�'q�u�QW�Ƃ��7iʹ���2x(��٨�G��|.�� Q#�j�n
b����a�i�Uh��}-�&���X�-�&��F#��ON��(Cm��
M_��YQ[��>�1��c0�h�Ch,܄XXJ�����ih�M!M�R�H �>D������  2�o�����jQ@XL�/��EK���s#�O�++*�B�K�X�f�J��,T�\Y�X���n�%�jwU��,p��b���̀ut�B���>�CIL&���?;ܕ�0n��nJV��'��n��B��CJ�&�/��_���V�y�v��׭h�>����wf���%\����s��P(G�Jh�'�wZ��S>>-4�u�Ϟ?�sQ}��*���~�����u	x7���ވ3�G%���P������9����qx����~?��8���9<��-w��p�B�c����L%�,���p�����m�����n��A7<��I<���8|4��q8�������9<��]���e>���9�_�z9|�Ws�D_��8|=�O��f?���8|
�o����çq�6���]~6����s8��������8�_����YJ:�C:�C:�C:�C:�C:���ù�����n����?W�c�m=�5��m�y�^�(�o��J̺H���x����D��̿��V�?��6�?���P�혿C�Ga������:��y�Ώ��U:����:?�n����t>��u~�-:����g|��Ώ'���|R��@��I�u~���O&����H�u~
���O%���i��:?��_��&���sH���텨������ˍ�����.�	���|��~���|��{~���\��%���$��x�������������V�_�_�3<�~�����y;��m{�����q��ݾ�h�OzR~��̝q+� s"��#2oP�Sǽ��1:ї;c+J��RH�8N_�}D.>���>����m^���W�kA@�
�J�5b�X~��օ��)�K��� ��hc����_�I"�����u+�:�k�`#D��z�W�ݚ�-�y;��ogƬ�X�������y���B�n�NO�����,���� ����
�=�����yW ��C�����y�$|���b��q�k�l&p{�W�!X�w����N��Zcn�����s�؃�x�|R`���y�XR�z��?1�3;Y΢�r�˙M��>�,'��3׻q�;���K'b����{��ұ���f&A,�	$�c?�,��4�����dٚ�bOͲ�,KU2˯ಿ��_���t���-�:��[�Y�n�2�H@g+ C��!6�����!v\��#����dI�0�ޕ��,��3t_�:�:�8��cK?��~�u�؎��h��B�m��a���0�E�B�A��d%����{��v<ʹ�0厖�A�F/j`/�0'����<$"�GJܻٞ{� �~~��`y�3�t?h��{,�{>@�a?V�6�|�t�x��kP��˭=������A��h���A��v�5�o�8��D*v��o �<�t����Un�����5p�`g~Gg�C06���C3A3��&������Qe2%��,�.��V톁�:A���x[��z�z�y�ô�م��M��D�����ߏ��� �3w[��X�s�C�C�y��H�>o��ng��^�Jރ禎<HR�I�v0-�"�ø�f<79*p�����i�%�V-uh�.B{�2�;co@/$�#���׹n�݇�AT�s��F5@S�� �}K��n"d�����,c!�� ���"Ocd;�b��%	�bob[ ;d��4��(�N��fA3\w��v���	���ޗRoh*�5ނ�u<�x���x.�ֻ&�1z�Q\�}$3.�\T{�s7,�n�B����{6ĴA6���|YDTى5�e*�Ҧ`��0�����L[?��6�p��"b���?J��2�/>�����G�����(�����[�d�:��i ���aR�C��c��Do���l�5�Ć�{k^��}Ȍ��^UH�m���s��`�z�1�v{1M��xF�1��^2�ܮ�7�},�Mz�QɌ�F`��]�� 9�=|������Q7[���D�'�m�9"jk��J�^�K����Tm_��e$3�k�ۭ�t��F������d%~l1�����w�J���X�r]�=�u]n��U*��w<�����'�&S�xW2c��a����C��[��Q�-����Ρھ}X���ìЉ�B�9l�v��������g��0�֓��?��\�6��*��a�6����&7��������ڄ[]��VnҡD��/��~3�%H�tH�tH�tH�tH�tH�tH�tH��r�з�c���H�/�x�ш���?�?o��[Z����� /ɖ�8�V::�������yz�/�^Yl�n[��v�-�]o$�d���D9�]@� �z+�@/�o~;����Db�MQ� �t(���䯉D�ۀ�>�)P�)��DХ@� � ����H$z��hЯ�-���O���n"Q�,�m@g�z��?x/��� �H�@ۀ��E�w�-7�(�My��c3���G�����H�sK3�k���C�u�	�@�͌�[6n���1��*WL�I�3�\t�cM���#�j��������o�;��"x��}�Z�3*
�����?!~5o]���n�^�k�y�ρ�c����� �'��y��i�٬V]�D�VP�,���I=� ���j�#�篃��)ߐ̏ΐ�=D����O��W�xT�w��-�?�eL�1������������r�h<�m,%��X���(b#��b^NKR�͐�v�Gg~3�k�c+M��r�}{2/�*Y��� ď��=\�C�v����_��	�_�����.Uz��B|&�٩||u2�X3W������}W �ρ����WB�ڃ����L�o����&��v��4��D�r��~�M��U�؟�)OX�~��l���jS�+�r���4{���-`S;���ծwvZ��-�5����,����y���V���5�!��C��?������o�ygv���gf�ٍ�M�����Ϻ:ag���*v���fg<ٙQv���f�^�F8r<��8Qv�C��o/=,�����xvVw'�`gtYy��W�Y����0;��K/��;�������M�F����ؙbV>;;���o���B���Ow'(����V�1��3�g20hb`���)��t=�m�n����nJwQ�Ci/�}�P���Q��Ei9�Ք����ҭ�vQ�M�.J{(�����vx��Y�i���++*�;f�7��Z��v;����8f�_,(p����i�Pr����'D|4���ks� I���U�S\q��x!Ż��;]��%�C�_���n�r�9�p���|��w%���^%��,��1urp5�ߧ8���e�-�F"��ˌ�s-g�.�/�?z6��Y�#Ƙ���B�1�~,܍�LI����T}�c�	��^	~��˺g�ټ^eE��)S�ӟ���);i�5\��O��l��@� �;VR	O�u)[���|�_$��~oB�	鯷����+�K�'���SD�į�'
������}g�$�C���uZʼ�K��O�"�a�r�_v?���m����­���=��ĞG�8b�(~#mw�kb�(s�.	^%��K�I�Q����L���K(O�E٤����#�I"�Q	�O���2/����h�m���Y�rvJ��_;�߈p��g{[F�~(����?�6��wh4�W�/{��,���x�`|���gėg9oP��u�3�
�o�gN�s=K%x�R�Xߵc����~����9?����2O�c��ϔ�Kƚ�m[jS��D�S�7��R�aj��h;6�ϫ?�x3��"��>�\��6����N³��������8���'Ϡ��,�5�������QT���>� �i��F�_I:xT�VՏ9� e �6�D�S4-����&�hl	j� ��LS �e!���6���ݬ4F}�A5om�Y8N���!)�o�������e���$���'3-�ǙB�7�p���5${K�w�B�z���K��,���xMK~��7&P�[5O�w>T�i�Y1oo��Ლ�Uճj)r��^��^�x)�]Z��K�]����B�f��e��:�n�5ŗ[9�P��HXλb�~�\*r����� v�������u��]56�����mnzjU��VP�FZU����o�A�$o�|�>���!T�)G2KP�G|���9�ΥV/�S�WԹ��j�ri[]��� ������n�Z��$�#+W��@(��c���0|�����):�,�󝞇̔v0� 4t<�hP���_j�j Q���a�'p8*t�a:�+��g4��z$=}ߘ�]^�g�XG4�"%��W,� x��:k�*��C1m��m0�B��D���NM:�C�:Y�yv$>'S�����j��s�kޯ���P���Sw�;߰)����{�=]�ytD�-X�x����Б���27�b5O�c���L�M:�W}��'ݡ�d���UU�u���5�B�����)�J��8�7-6(��ew�.�9�E�*An�� �J����� �}a��ae��������l�D7��)MIʡ�0r~��[�VE�,���ЛP�dTOz�X�*s���+;�u��,�X��{���F*��P��~�˙b����p��l�y�4��H�.��r�9��a��)?���澭8�G����������r���>^�Bq�C!2G����8c�[5_PX*a�̮��Mq�#Z�	�t�E#0������!8=�f_�Yq6��B�(���!��<�B\4��C	�U[������t6E�E,�W��4/5��~�s��C{s ��?,U7��m<���L>��
���@<S���@��7��b�Ǣ�Rؾ��{P,�/R!�Ҽ/g���X��!��$a�'�T�B~��%�o��_%���3��g�̢��g�1\�l��J�l����㷆ؾ6�;N�S��B��Y~�/�h���U�_TȞ3�پ3��JR��Z��
�)����e���X��N�/�<�Wg��ã�SM�?�p�dB�a��OiEIm�o
�#.|��;���f
T(O̿K,���������Ci��D��	��>�9Bz�~�P�����6!��^�˾K&+�u!���F��͘^,�!��H�yV,��B�X1�w��wϦ�j���,?��Zi����'����߭�����2�|�<�������^E�W�b�S,���~M5����¹�����Ma���˅�������?W�-&Ԫ�/Ϳ����ރ0�F+����ȵ��s��8���"t��!�"����j�l~�� ���O#��G��k��9�0���݅��%���4���O#�w�/�o^�}��\)�.^PR@�֣W]ѩ������Ǝ�o #�S�a��LjA4P(.q�1�_a���0a6�)�r��%�e_�_�A=:�K�_�y^�"	��(¥N���1EIu:&��)����2Ѷ��I�H;�&'N�H%�N�>�&mO�E�AQ��t��"M9�S�'�Q��{T��)�v;-�
��2�5���&;uy�	����S�7�x٩�o�x٩L� {�\�u6{~R��0�J�Cz�����#9N���E����(~9m�v5�Y>�'{{�q�����;���R�B��/���%�z	~��B�gz3���_b5ǯ�&�0�C�$��$��R؈�t����῰:�O�����vz_66~7��l_��g��>�k|�I�md�C�(�9um4�K�������l/ҳ!Q��c��^N�X���s8< �g�F$r�$�wP�.��o	��[͏H��8zY8��ʥ���_
�٩��J�������}�=?��e1�o��ܞ�X���ҳ�K�ҳ�+WK䯳�۳�K���k�|��ǥ���=!=�����)��/K���Ğ��9$�w�������=F�ӹ����Vs{�����\(�g��˥��y�������=C=� ��m�|f�.��n!=�OJ�?+�g��E��^�=_��3ۖ�o��|[2��ʥ����K�̵%����Ŝ�ɼ%��s8��_��:ϡ$��7���M�9�_unҳ�e���r�z_�3@^�v�ٻz�sD�&D.�:{]��+s�Kw��Q���{
�H\ܿ^��b��1唲MJ�'Ѹe�Q�"�r�@7��zaE�g:�U.����N�=Y>j_q��BE���A�����(�].1��^�݊�N�ö�|>����h�Q��^��)�˟Ge��w��-f'd?���W1��h��ż�v��?ڤ��R�w	�h���3��b��V"Z���SJ��Q(���^�kż�����O��E�����G����O�K�G��l�Ƹ��e��e���vA��ӇS�-��.i:�C:|v��Snd� �  